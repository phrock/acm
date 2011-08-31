/*
  ID:   aphrodi1
  LANG: C++
  PROG: cryptcow
*/
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#include <assert.h>
#include <time.h>

#define MAX_MSG_LEN     76
#define MAX_N           9       // (75-47)/3
#define MAX_N_TRIPLES   (MAX_N*MAX_N*MAX_N)
#define C_          0
#define O_          1
#define W_          2           
#define NOT_COW     3
 
char Moo[] = "Begin the Escape execution at the Break of Dawn";
int Moo_len = 47;
 
char Hmm[MAX_MSG_LEN];  // message received
int Hmm_len;
int N;      // number of encryptions
 
int cowpos[3*MAX_N + 2];    // +2 for the start and end
int T;      // number of triples
 
int triple[MAX_N_TRIPLES + 1][3];   // triples will be numbered
                                    // starting from 1
                                    // don't ask why
 
// node in linked list
struct llnode_t {
    int data;
    llnode_t *next;
} *its_triple[3*MAX_N+1] = {0};
 
// for curiosity's sake:
int n_calls_to_find_tripleset = 0;
int n_calls_to_find_ordering = 0;
int starttime;
 
void input ();
int submoo (const char *, int);
void subhmm (char *, int, int);
void init ();
int thingy (char);
void output (bool);
void find_tripleset (int decoded_len, int last_seg_start, int *its_triple_used);
void find_ordering (int *curcowpos, int *triple_used, int n_decodings_applied);
int main ();
 
// add a node to the beginning of linked list
void addnode (llnode_t **np, int data)
{
    llnode_t *temp = *np;
    *np = new llnode_t;
    (*np)->data = data;
    (*np)->next = temp;
}
 
int thingy (char c)
{
    switch (c) {
    case 'C':
        return C_;
    case 'O':
        return O_;
    case 'W':
        return W_;
    default:
        return NOT_COW;
    }
}
 
// is word a subsequence of Moo, starting from position 'start' in Moo?
// if so, return position of first character in Moo that starts it
// otherwise return -1
int submoo (const char *word, int start)
{
    int word_len = strlen (word);
 
    if (word_len == 0)
        return start;
 
    int i, j;
 
    for (i = start; i <= Moo_len - word_len; i++) {
        for (j = 0; j < word_len && Moo[i+j] == word[j]; j++)
            ;
        if (j == word_len)
            return i;
    }
 
    return -1;
}
 
// get Hmm[start..end]
void subhmm (char *target, int start, int end)
{
    int i, j = 0;
    for (i = start; i <= end; i++)
        target[j++] = Hmm[i];
    target[j] = '\0';
}
 
// output the answer
void output (bool result)
{
    FILE *fout = fopen ("cryptcow.out", "w");
    if (result) {
        fprintf (fout, "1 %d\n", N);
        printf ("The answer is yes.\n");
    } else {
        fprintf (fout, "0 0\n");
        printf ("The answer is no.\n");
    }
    fclose(fout);
 
    printf ("%d calls to find_tripleset; %d calls to find_ordering.\n",
            n_calls_to_find_tripleset, n_calls_to_find_ordering);
    printf ("Runtime: %g seconds.\n", (double) (clock () - starttime) / CLOCKS_PER_SEC);
    exit (0);
}
 
// just get the input
void input ()
{
    FILE *fin = fopen ("cryptcow.in", "r");
    fscanf (fin, "%[^\n]", Hmm);
    fclose (fin);
 
#ifndef NDEBUG
    printf ("%s\n", Hmm);
#endif
}
 
// do stuff
void init ()
{
    Hmm_len = strlen (Hmm);
 
    // is length acceptable?
    if (Hmm_len < Moo_len || (Hmm_len - Moo_len) % 3 != 0) {
        printf ("Length badness.\n");
        output (0);
    } else
        N = (Hmm_len - Moo_len) / 3;
 
    // while forming array cowpos[],
    // make sure N = # of C's = # of O's = # of W's
    int i;
    int chartype;
    int ncows[3] = {0};
    int totncows = 1;   // 1, and not 0, because of the start
 
    cowpos[0] = -1;
 
    for (i = 0; i < Hmm_len; i++) {
        chartype = thingy (Hmm[i]);
        if (chartype != NOT_COW) {
            if (++ncows[chartype] > N) {
                // too many cows
                printf ("Too many of one type of cow.\n");
                output (0);
            }
            cowpos[totncows++] = i;
            if (totncows == 1 && chartype != C_) {
                // first cow is not a 'C'
                printf ("First cow not C.\n");
                output (0);
            } else if (totncows == 3*N+1 && chartype != W_) {
                // last cow is not a 'W'
                printf ("Last cow not W\n");
                output (0);
            }
        } else {
            if (totncows == 1 && Hmm[i] != Moo[i]) {
                // first segments don't match
                printf ("First segments don't match.\n");
                output (0);
            } else if (totncows == 3*N+1 && Hmm[i] != Moo[i+Moo_len-Hmm_len]) {
                // last segments don't match
                printf ("Last segments don't match.\n");
                output (0);
            }
        }
    }
 
    cowpos[3*N+1] = Hmm_len;
 
    if (ncows[0] != N || ncows[1] != N || ncows[2] != N) {
        printf ("Wrong number of some cow.\n");
        output (0);
    }
    if (Hmm_len == Moo_len)
        output (1);
 
    // find the triples that might work
    int c, o, w;
    char segment[3][2][MAX_MSG_LEN];    // [C, O, or W][left or right][]
    char subword[MAX_MSG_LEN];
    int c_start;
 
    T = 0;
    for (c = 1; c <= 3*N; c++) {
        if (Hmm[cowpos[c]] != 'C')
            continue;
 
        subhmm (segment[C_][0], cowpos[c-1] + 1, cowpos[c] - 1);
        subhmm (segment[C_][1], cowpos[c] + 1, cowpos[c+1] - 1);
 
        c_start = submoo (segment[C_][0], 0);
 
        if (c_start == -1) {
            printf ("Some segment does not exist.\n");
            output (0);
        }
 
        for (o = 1; o <= 3*N; o++) {
            if (Hmm[cowpos[o]] != 'O')
                continue;
 
            subhmm (segment[O_][0], cowpos[o-1] + 1, cowpos[o] - 1);
            subhmm (segment[O_][1], cowpos[o] + 1, cowpos[o+1] - 1);
 
            // the segment left of c and the segment right of o must fit
            // together to form a subsequence of Moo
 
            strcpy (subword, segment[C_][0]);
            strcat (subword, segment[O_][1]);
            if (submoo (subword, c_start) == -1) {
                assert (submoo (subword, 0) == -1);
                continue;
            }
 
            for (w = 1; w <= 3*N; w++) {
                if (Hmm[cowpos[w]] != 'W')
                    continue;
 
                subhmm (segment[W_][0], cowpos[w-1] + 1, cowpos[w] - 1);
                subhmm (segment[W_][1], cowpos[w] + 1, cowpos[w+1] - 1);
 
                // the segment left of o and the segment right of w must fit
                strcpy (subword, segment[O_][0]);
                strcat (subword, segment[W_][1]);
                if (submoo (subword, 0) == -1)
                    continue;
 
                // the segment left of w and the segment right of c must fit
                strcpy (subword, segment[W_][0]);
                strcat (subword, segment[C_][1]);
                if (submoo (subword, 0) == -1)
                    continue;
 
                // finally, after all these tests we have found a triple
                // worthy of further consideration
                T++;
                triple[T][C_] = c;
                triple[T][O_] = o;
                triple[T][W_] = w;
                addnode (&its_triple[c], T);
                addnode (&its_triple[o], T);
                addnode (&its_triple[w], T);
            }
        }
    }
 
    //printf ("All %d triples found.\n", T);
 
    // verify that each cow has at least one triple
    for (i = 1; i <= 3*N; i++) {
        if (its_triple[i] == 0) {
            printf ("Cow %d has no triples.\n", i);
            output (0);
        }
    }
 
#ifndef NDEBUG
    printf ("Initialization results (after %g seconds):\n",
            (double) (clock () - starttime) / CLOCKS_PER_SEC);
    printf ("\tNumber of encrpytions (possibly): %d.\n", N);
    printf ("\tNumber of triples: %d.\n", T);
#endif
}
 
// use this function recursively
// find a set of triples given:
// - the length of Moo already decoded (i.e., the position in Moo from which
//   further consideration is necessary)
// - the id of the cow to the left of the last segment used,
// - the triples that you've already committed to using
void find_tripleset (int decoded_len, int last_seg_start, int *its_triple_used)
{
    n_calls_to_find_tripleset++;
 
    //  printf ("Trying to find tripleset.\n");
 
    int i;
    int last_seg_end = last_seg_start+1;
    int last_seg_end_type = thingy (Hmm[cowpos[last_seg_end]]);
    int last_seg_len;
    int next_seg_start;
    int triple_to_use;
 
    // first see if the segment from last_seg_start to last_seg_end really fits
    assert (0 <= last_seg_start && last_seg_end <= 3*N+1);
 
    last_seg_len = cowpos[last_seg_end] - cowpos[last_seg_start] - 1;
    if (decoded_len + last_seg_len > Moo_len)
        return;
    for (i = 0; i < last_seg_len &&
             Moo[decoded_len + i] == Hmm[cowpos[last_seg_start]+1+i]; i++)
        ;
    if (i < last_seg_len)
        return;
 
    //  printf ("The last segment does fit.\n");
 
    // the last segment indeed fits
    decoded_len += last_seg_len;
 
    if (last_seg_start == 3*N && decoded_len == Moo_len) {
        // we have found a successful tripleset!
 
#ifndef NDEBUG
        printf ("Tripleset found after %d calls to find_tripleset.\n",
                n_calls_to_find_tripleset);
#endif
 
        int triple_used[MAX_N];
        int curcowpos[3*MAX_N+2];
        int j = 0;
        for (i = 1; i <= 3*N; i++) {
            if (Hmm[cowpos[i]] == 'C') {
                triple_used[j++] = its_triple_used[i];
            }
        }
        memcpy (curcowpos, cowpos, sizeof (*cowpos) * (3*N+2));
 
        find_ordering (curcowpos, triple_used, 0);
        return;     
    }
 
    assert (0 <= last_seg_end_type && last_seg_end_type < 3);
    assert (last_seg_end <= 3*N);
 
    if ((triple_to_use = its_triple_used[last_seg_end]) != 0) {
        // the next segment to be used has already been decided
        next_seg_start = triple[triple_to_use][(last_seg_end_type + 1) % 3];
        find_tripleset (decoded_len, next_seg_start, its_triple_used);
    } else {
        // the next segment to be used is up for grabs
        //      printf ("The next segment to be used is up for grabs.\n");
 
        llnode_t *trytriple;
        assert (0 < last_seg_end && last_seg_end <= 3*N);
 
        for (trytriple = its_triple[last_seg_end];
             trytriple != 0; trytriple = trytriple->next) {
            triple_to_use = trytriple->data;
 
            assert (1 <= triple_to_use && triple_to_use <= T);
            assert (1 <= triple[triple_to_use][(last_seg_end_type + 1) % 3]);
            assert (triple[triple_to_use][(last_seg_end_type + 1) % 3] <= 3*N);
 
            if (its_triple_used[triple[triple_to_use]
                                [(last_seg_end_type + 1) % 3]] != 0)
                {
                    continue;
                }
 
            if (its_triple_used[triple[triple_to_use]
                                [(last_seg_end_type + 2) % 3]] != 0)
                {
                    continue;
                }
 
            assert (last_seg_end == triple[triple_to_use][last_seg_end_type]);
 
            its_triple_used[last_seg_end] = triple_to_use;
            its_triple_used[triple[triple_to_use][(last_seg_end_type + 1) % 3]]
                = triple_to_use;
            its_triple_used[triple[triple_to_use][(last_seg_end_type + 2) % 3]]
                = triple_to_use;
 
            next_seg_start = triple[triple_to_use][(last_seg_end_type+1) % 3];
            find_tripleset (decoded_len, next_seg_start, its_triple_used);
 
            its_triple_used[last_seg_end] = 0;
            its_triple_used[triple[triple_to_use][(last_seg_end_type + 1) % 3]]
                = 0;
            its_triple_used[triple[triple_to_use][(last_seg_end_type + 2) % 3]]
                = 0;
        }
    }
}
 
// use this function recursively
// find an ordering of the triples given in triple_used
// that accomplishes the task given:
// - the current positions of all cows, which includes
//   information about which triples have already been used
//   (those cows that have already been used are at position -1)
// - which triples are to be used
void find_ordering (int *curcowpos, int *triple_used, int n_decodings_applied)
{
    n_calls_to_find_ordering++;
 
    if (n_decodings_applied == N)
        output (1);
 
    int nextcowpos[3*MAX_N+2];
 
    int i, j, cpos, opos, wpos;
    for (i = 0; i < N; i++) {
        cpos = curcowpos[triple[triple_used[i]][C_]];
        opos = curcowpos[triple[triple_used[i]][O_]];
        wpos = curcowpos[triple[triple_used[i]][W_]];
        if (cpos >= opos || opos >= wpos) {
            continue;
        }
        for (j = 1; j <= 3*N; j++) {
            if (curcowpos[j] == -1)
                nextcowpos[j] = -1;
            else if (curcowpos[j] < cpos)
                nextcowpos[j] = curcowpos[j];
            else if (curcowpos[j] == cpos)
                nextcowpos[j] = -1;
            else if (curcowpos[j] < opos)
                nextcowpos[j] = curcowpos[j] + wpos - opos - 2;
            else if (curcowpos[j] == opos)
                nextcowpos[j] = -1;
            else if (curcowpos[j] < wpos)
                nextcowpos[j] = curcowpos[j] + cpos - opos - 1;
            else if (curcowpos[j] == wpos)
                nextcowpos[j] = -1;
            else
                nextcowpos[j] = curcowpos[j] - 3;
        }
        find_ordering (nextcowpos, triple_used, n_decodings_applied+1);
    }
}
 
int main ()
{
    starttime = clock ();
    input ();
    init ();
 
    int its_triple_used[3*MAX_N+1] = {0};
    find_tripleset (0, 0, its_triple_used);
 
    // if you're still alive, the answer must be no
    output (0);
    return 0;
}
