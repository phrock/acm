#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloca.h>
#include <assert.h>

// #define DEBUG

#ifdef DEBUG
#define bug(fmt, ...) do {                                      \
        fprintf( stderr, "[%s]: "fmt, __func__, ##__VA_ARGS__); \
    } while(0)

#else
#define bug(fmt, ...) do {                      \
    } while(0)

#endif

#define MAX_STATES 50
#define MAX_DEADLINE 1000

// states has order in set, order is important
typedef struct set_s
{
    int items[MAX_STATES];  // items[idx] = some_state
                             
    int size; // marks valid states in the set
    int capacity;  // equals nr_states
    int first;  // pos of first valid state 
} set_t;

#define CACHE_SIZE (MAX_STATES<<2)
static set_t __set_caches[CACHE_SIZE];

void obj_cache_init()
{
    memset( __set_caches, 0xff, sizeof __set_caches );
}

void* obj_alloc()
{
    int i = 0;
    for ( ; i < CACHE_SIZE; ++i ) {
        if ( __set_caches[i].capacity <= 0 )
            return (void*)&__set_caches[i];
    }

    assert( 0 );
    return NULL;
}

void obj_free(void* ptr)
{
    // do nothing
    /* set_t* set = ptr; */
    /* set->capacity = -1; */
}

set_t* set_calloc( int nr_states )
{
    set_t *set = malloc( sizeof(set_t) );
    /* set_t *set = (set_t*)obj_alloc(); */
    memset( set, 0xff, sizeof *set );
    
    set->size = 0;
    set->first = -1;
    set->capacity = nr_states;
    return set;
}

void set_free( set_t *set ) 
{
    obj_free( set );
}

static inline int set_is_state_in( set_t* set, int state )
{
    if ( set->size == 0 )
        return 0;

    int i = 0;
    for (; i < set->size; ++i ) {
        if ( set->items[i] == state )
            return 1;
    }
    return 0;
}

static inline void set_push_state( set_t* set, int state )
{
    set->items[set->size++] = state;
}

static inline int set_last_state( set_t *set )
{
    if ( set->size == 0 )
        return -1;
    return set->items[set->size-1];
}

static inline int set_is_empty( set_t* set ) 
{
    return set->size <= 0;
}

// pop first state. if empty, return -1
static inline int set_pop_state( set_t* set )
{
    if ( set_is_empty(set) )
        return -1;

    return set->items[--set->size];
}

void set_clear( set_t* set )
{
    memset( set, 0xff, sizeof set->items );
    set->size = 0;
}

set_t* set_copy( set_t* other ) 
{
    set_t* copy = malloc( sizeof *other );
    memcpy( copy, other, sizeof(*other) );
    return copy;
}

void dump_set( const char* title, set_t* set ) 
{
    char msg[1024] = "";
    int i;
    for ( i = 0; i < set->size; ++i ) {
        assert ( set->items[i] >= 0 );
        sprintf( msg + strlen(msg), "%d -> ", set->items[i] );
    }
    bug( "%s: %s\n", title, msg );
}

typedef struct problem_s
{
    int *states;
    int *tolls;
    int nr_states;
    int deadline;

    int accept_time;
    int accept_toll;
} Problem;

// return completion set of arg set with state in it, residual should not
// contain market state ( nr_states-1 )
void get_state_residual( set_t* set, set_t* residual, int nr_states )
{
    // version 2
    int peeks[MAX_STATES];

    int i = 0;
    for ( ; i < nr_states-1; i++ ) {
        peeks[i] = i;
    }
    
    for ( i = 0; i < set->size; i++ ) {
        peeks[ set->items[i] ] = -1;
    }

    for ( i = 1; i < nr_states-1; i++ ) {
        if ( peeks[i] > 0 )
            set_push_state( residual, peeks[i] );
    }
}

void print_route( Problem* problem, set_t* applied )
{
    dump_set( "full route", applied );
    bug( "time: %d, toll: %d\n", problem->accept_time, problem->accept_toll );
    bug( "%d %d\n", problem->accept_time, problem->accept_toll );
}

// given applied states already, try next state
int find_next_route(  Problem* problem, set_t* applied, int cur_time, int cur_toll )
{
    int nr_states = problem->nr_states,
        deadline = problem->deadline,
        *states = problem->states,
        *tolls = problem->tolls;

    int last = set_last_state( applied );

    {
        int toll = cur_toll + *(tolls + last * nr_states + nr_states-1);
        if ( problem->accept_toll == 0 || problem->accept_toll >= toll ) {
            int incr_time = *(states + last * nr_states + nr_states-1);
            if ( incr_time + cur_time <= deadline ) {
                if ( (problem->accept_toll == toll
                      && problem->accept_time > incr_time + cur_time)
                     || (problem->accept_toll > toll)
                     || (problem->accept_toll == 0) ) {
                    problem->accept_time = cur_time + incr_time;
                    problem->accept_toll = toll;
                    /* set_t* copy = set_copy( applied ); */
                    /* set_push_state( copy, nr_states-1 ); */
                    /* dump_set( "accept route", copy ); */
                    /* bug( "route time %d, cost %d\n", problem->accept_time, */
                    /*      problem->accept_toll ); */
                    /* free( copy ); */
                } 
            }
        }
    }

    set_t *residual = set_calloc( nr_states );
    get_state_residual( applied, residual, nr_states );
    
    while ( !set_is_empty(residual) ) {
        int peek = set_pop_state( residual );
        int cur_time2 = cur_time, cur_toll2 = cur_toll;

        /* dump_set( "find_next_route applied", applied ); */
        bug( "last: %d, peek: %d, cur_time: %d, cur_toll: %d\n",
             last, peek, cur_time2, cur_toll2 );
        
        int incr_toll = *(tolls + last * nr_states + peek);
        if ( problem->accept_toll != 0
             && problem->accept_toll < cur_toll2 + incr_toll ) {
            bug( "last -> peek toll = %d, exceeded \n", incr_toll );
            continue;
        }
        
        int incr_time = *(states + last * nr_states + peek);
        if ( cur_time2 + incr_time > deadline ) {
            bug( "last -> peek time = %d, exceeded \n", incr_time );
            continue;
        }
        
        cur_time2 += incr_time;
        cur_toll2 += incr_toll;

        set_t *copy = set_copy( applied );
        set_push_state( copy, peek );
        /* dump_set( "applied copy", copy ); */
        find_next_route( problem, copy, cur_time2, cur_toll2 );
        set_free( copy );
    }
    set_free( residual );
    return 0;
}

// size means length of width and height
__attribute__((unused)) static void dump_matrix( int* matrix, int size )
{
#ifdef DEBUG
    int i, j;
    for ( i = 0; i < size; ++i ) {
        for ( j = 0; j < size; ++j ) {
            fprintf( stderr, "%d ", *(matrix + i*size + j) );
        }
        fputc( '\n', stderr );
    }
    fputc( '\n', stderr );
#endif    
}

void do_test(Problem* problem)
{
    set_t *set = set_calloc( 10 );
    int i = 0;
    for (; i < set->capacity; ++i )
        assert( set->items[i] == -1 );
    
    i = 0;
    for ( ; i < 4; ++i) {
        set_push_state(set, i);
    }

    set_pop_state( set );
    set_pop_state( set );
    set_push_state( set, 4 );
    set_push_state( set, 8 );
    dump_set( "set: ", set );
    
    set_t* residual = set_calloc( 10 );    
    get_state_residual( set, residual, 10 );
    set_free( residual );
    
    print_route( problem, set );
    set_free( set );
}

int main(int argc, char *argv[])
{
    obj_cache_init();
    int* states_space = (int*) malloc( MAX_STATES * MAX_STATES * sizeof(int) );
    int* tolls_space = (int*) malloc( MAX_STATES * MAX_STATES * sizeof(int) );
    
    while ( 1 ) {
        int nr_states = 0, deadline = 0;
        scanf( "%d %d", &nr_states, &deadline );
        if ( !nr_states && !deadline )
            break;

        Problem *problem = malloc( sizeof(Problem) );
        problem->accept_toll = 0;
        problem->accept_time = deadline;
        
        problem->deadline = deadline;
        problem->nr_states = nr_states;
        problem->states = states_space;
        problem->tolls = tolls_space;

        int i = 0;
        for ( ; i < nr_states; ++i ) {
            int j = 0;
            for ( j = 0; j < nr_states-1; ++j )
                scanf( "%d ", problem->states + i*nr_states + j );
            scanf( "%d", problem->states + i*nr_states + nr_states - 1 );
        }

        for ( i = 0; i < nr_states; ++i ) {
            int j = 0;
            for ( j = 0; j < nr_states-1; ++j )
                scanf( "%d ", problem->tolls + i*nr_states + j );
            scanf( "%d", problem->tolls + i*nr_states + nr_states - 1 );
        }

        set_t *applied = set_calloc( nr_states );
        set_push_state( applied, 0 );
        find_next_route( problem, applied, 0, 0 );
        
        printf( "%d %d\n", problem->accept_toll, problem->accept_time );
        free ( problem );
    }
    
    return 0;
}
