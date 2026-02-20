#include <bits/stdc++.h>
using namespace std;

void Pair()
{
    pair<int, int> p = {1, 2};
    cout << "Normal pair:" << p.first << " " << p.second << endl;
    // nested pair
    pair<int, pair<int, int>> q = {1, {2, 3}};
    cout << "Nested pair:" << q.first << " " << q.second.second << endl;
    // array of pair
    pair<int, int> pairArray[] = {{1, 2}, {2, 3}, {3, 4}};
    cout << "Array of pair" << pairArray[0].first << " " << pairArray[2].second << endl;
}

void Vector()
{
    // single linked list is mantined for vector
    vector<int> v;
    v.push_back(0);
    v.emplace_back(1);
    v.emplace_back(2);
    v.emplace_back(3);
    v.emplace_back(4);

    cout << "Normal Vector:" << v[0] << " " << v[1] << endl;

    vector<pair<int, int>> v2;
    v2.push_back({1, 2});
    // dont need to use {} as emplace back already takes object
    v2.emplace_back(3, 4);

    cout << "vector of pair:" << "{" << v2[0].first << "," << v2[0].second << "}" << "," << "{" << v2[1].first << "," << v2[1].second << "}" << endl;

    // vector of size 5 filled with 100
    vector<int> v3(5, 100);
    // vector of size 5 with garbage value
    // its size can be increased
    vector<int> v4(5);

    // copying a vector
    vector<int> v5(v3);

    // vector iterators
    vector<int>::iterator it = v.begin();
    it++;
    cout << "Using iterator->v[1]:" << *it << endl;
    it = it + 2;
    cout << "v[3]:" << *it << endl;
    // v.end point to one index after the last element
    it = v.end();
    it--;
    cout << "v end-1:" << *it << endl;

    vector<int>::reverse_iterator it2 = v.rend();
    it2--;
    cout << "v rend:" << *it2 << endl;
    it2--;
    cout << "v rend--:" << *it2 << endl;

    it2 = v.rbegin();
    cout << "v rbegin:" << *it2 << endl;
    it2++;
    cout << "v rbegin++:" << *it2 << endl;
    // Using iterator in loop
    cout << "Using iterator in loop v:";
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "Using auto iterator in loop v:";
    // Using itreator as auto
    // auto assinges data type automaticaly
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    // using for each loop
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    // erase
    v.erase(v.begin());                // erase 1 element
    v.erase(v.begin(), v.begin() + 2); // erases 3 element

    // insert
    v.insert(v.begin(), 200);   // 1 element
    v.insert(v.begin(), 2, 20); // inserts 2 20s in v begin

    cout << "v size:" << v.size() << endl;

    v.pop_back();

    // swap
    v3.swap(v4);
}

void List()
{
    // doubly linked list is mantained for list
    // inserting in the front is very cheap then vector

    list<int> ls;
    ls.push_back(2);
    cout << "ls.push_back(2):";
    for (int i : ls)
        cout << i << " ";
    cout << endl;
    ls.emplace_back(3);
    cout << "ls.emplace_back(3):";
    for (int i : ls)
        cout << i << " ";
    cout << endl;
    ls.push_front(5);
    cout << "ls.push_front(5):";
    for (int i : ls)
        cout << i << " ";
    cout << endl;
    ls.emplace_front();
    cout << "ls.emplace_front():";
    for (int i : ls)
        cout << i << " ";
    cout << endl;
    // rest same as vector
}

void Deque()
{
    deque<int> dq;
    dq.push_back(1);     // [1]
    dq.emplace_back(2);  // [1, 2]
    dq.push_front(4);    // [4, 1, 2]
    dq.emplace_front(3); // [3, 4, 1, 2]

    dq.pop_back();  // removes 2 → [3, 4, 1]
    dq.pop_front(); // removes 3 → [4, 1]

    int a = dq.back();
    int b = dq.front();
    cout << a << " " << b;
}

void Stack()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.emplace(5);

    cout << "top:" << st.top() << endl;
    st.pop();
    cout << "new top after pop:" << st.top() << endl;
    cout << "st size:" << st.size() << endl;
    cout << "is it empty:" << st.empty() << endl;
    stack<int> st1, st2;
    st1.swap(st2);
}

void Queue()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(3);
    q.back() += 2;
    cout << "Adding 2 to the back:" << q.back() << endl;
    cout << "front:" << q.front() << endl;

    q.pop();
    cout << "After poping from queue  front:" << q.front();
}

void Priority_Queue()
{
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10);

    cout << "pq-top also max-heap-top:" << pq.top() << endl;
    pq.pop();
    cout << "after pop pq-top:" << pq.top() << endl;

    priority_queue<int, vector<int>, greater<int>> pq2;

    pq2.push(5);
    pq2.push(2);
    pq2.push(8);
    pq2.emplace(18);
    cout << "min priority queue/minheap-top:" << pq2.top();
}

void Set()
{
    // Sorted order
    set<int> st;
    st.insert(2);
    st.emplace(4);
    st.insert(2); // No repeating
    st.insert(3);
    st.insert(5);

    for (int i : st)
    {
        cout << i << " ";
    }
    cout << endl;
    auto it = st.find(3); // returns iterator
    cout << *it << endl;
    ;

    auto it2 = st.find(8);

    if (it2 != st.end())
    {
        cout << *it2 << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    int cnt=st.count(3);//gives 1 if exist else 0 cant be more then 1 coz its set

    st.erase(it);//erases the value at "it"
    for (int i : st)
    {
        cout << i << " ";
    }
    cout << endl;
}

void MultiSet(){
    //ordered and can store repeated values
    multiset<int>ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(1);
    for (int i : ms)
    {
        cout << i << " ";
    }
    cout << endl;
    ms.erase(1);//deletes both 1
    for (int i : ms)
    {
        cout << i << " ";
    }
    cout << endl;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
      for (int i : ms)
    {
        cout << i << " ";
    }
    cout << endl;
    //let delete only one 1
    ms.erase(ms.find(1));
     for (int i : ms)
    {
        cout << i << " ";
    }
    cout << endl;
}

void UnordereSet(){
    //random order
    //all set functons leaving lower and upperbound function
    unordered_set<int> us;
    us.insert(1);
    us.insert(2);
    us.insert(3);
    us.insert(1);
    us.insert(4);
    for(int i:us){
        cout<<i;
    }
    cout<<endl;

}

void Map(){
    //stores in sorted order ,first value is key
    //no dublicate keys
   map<int,int>mp;
   mp[1]=2;
   mp.insert({3,4});
   mp.emplace(2,2);
   for(auto i:mp){
    cout<<"{"<<i.first<<","<<i.second<<"}"<<" ";
   }
   cout<<endl;
   map<pair<int,int>,int>mp2;
   mp2[{2,3}]=10;
   
   cout<<mp[1]<<endl;
   cout<<mp[5]<<endl;//notFound=0 or null

   auto it=mp2.find({2,3});
   cout<<"{"<<(*it).first.first<<","<<(*it).first.second<<"}"<<"="<<(*it).second<<endl;
   

   
}

void MultiMap(){
    //everything is same as map, only it can store multipe keys of same value
    //mp[keys] cant be used here
}

void UnorderdMap(){
    //Same as set and unordered set diffrence
}

bool comp(pair<int,int> p1,pair<int,int> p2){
    if(p1.second<p2.second)return true;
    if(p1.second>p2.second)return false;

    if(p1.first>p2.first)return true;
    return false;
}
void Extra(){
    //sort()
    int a[]={5,3,4,6,2,24,56,7};
    int n2=sizeof(a)/sizeof(a[0]);
    int *it=a;
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    sort(it,it+n2);
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    pair<int,int> a1[]={{1,2},{2,1},{4,1},{5,1}};
    int n=sizeof(a1)/sizeof(a1[0]);
    //sort it according to seconde element
    //if seconde element is same,then 
    //sort it according to first element but in descending order
    auto *it2=a1;
    for(pair i:a1){
       cout<<"{"<<i.first<<","<<i.second<<"} ";
    }
    cout<<endl;
    sort(it2,it2+n,comp);
    for(pair i:a1){
       cout<<"{"<<i.first<<","<<i.second<<"} ";
    }
    cout<<endl;

    int num=7;
    int cnt=__builtin_popcount(num);
    cout<<"No. of 1s in binary 7:"<<cnt<<endl;

    long long num2=89;
    int cnt2=__builtin_popcountll(num2);
    cout<<"No. of 1s in binary 89:"<<cnt2<<endl;

    string s="123";
    //next_permutation() changes string vector array etc to its next greatest value and if you want all the permutation keep in mind to sort it before applying the function
    sort(s.begin(), s.end());
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));

    cout<<"Max element in a:"<<*max_element(it,it+n2);
}

int main()
{
    // Pair();
    // Vector();
    // List();
    // Deque();
    // Stack();
    // Queue();
    // Priority_Queue();
    // Set();
    // MultiSet();
    // UnordereSet();
    // Map();
    Extra();
    return 0;
}