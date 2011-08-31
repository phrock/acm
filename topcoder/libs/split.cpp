template<class T> vector<T> split(const string& s, const string& delim = " ") {
  vector<string> aux;
  string t;
  for (int i = 0; i != (int)(s).size(); ++i)
    if (delim.find(s[i]) != string::npos) { if (!t.empty()) { aux.push_back(t); t = ""; } }
    else t += s[i];
  if (!t.empty()) aux.push_back(t);
  vector<T> res;
  for (int i = 0; i < (int)(aux).size(); ++i)
    res.push_back(*({stringstream ss; ss << (aux[i]); static T _; ss >> _; &_;}));
  return res;
}
