#include<bits/stdc++.h>
using namespace std;

void Pair(){
    pair<int,int> p={1,2};
    cout<<"Normal pair:"<<p.first<<" "<<p.second<<endl;
    //nested pair
    pair<int,pair<int,int>> q={1,{2,3}};
    cout<<"Nested pair:"<<q.first<<" "<<q.second.second<<endl;
    //array of pair
    pair<int,int> pairArray[]={{1,2},{2,3},{3,4}};
    cout<<"Array of pair"<<pairArray[0].first<<" "<<pairArray[2].second<<endl;
}

void Vector(){
    //single linked list is mantined for vector
    vector<int>v;
    v.push_back(0);
    v.emplace_back(1);
    v.emplace_back(2);
    v.emplace_back(3);
    v.emplace_back(4);

    cout<<"Normal Vector:"<<v[0]<<" "<<v[1]<<endl;

    vector<pair<int,int>> v2;
    v2.push_back({1,2});
    //dont need to use {} as emplace back already takes object
    v2.emplace_back(3,4);

    cout<<"vector of pair:"<<"{"<<v2[0].first<<","<<v2[0].second<<"}"<<","<<"{"<<v2[1].first<<","<<v2[1].second<<"}"<<endl;

    //vector of size 5 filled with 100
    vector<int>v3(5,100);
    //vector of size 5 with garbage value
    //its size can be increased
    vector<int>v4(5);

    //copying a vector
    vector<int>v5(v3);

    //vector iterators
    vector<int>::iterator it=v.begin();
    it++;
    cout<<"Using iterator->v[1]:"<<*it<<endl;
    it=it+2;
    cout<<"v[3]:"<<*it<<endl;
    //v.end point to one index after the last element
    it=v.end();
    it--;
    cout<<"v end-1:"<<*it<<endl;

    vector<int>::reverse_iterator it2 =v.rend();
    it2--;
    cout<<"v rend:"<<*it2<<endl;
    it2--;
    cout<<"v rend--:"<<*it2<<endl;

    it2=v.rbegin();
    cout<<"v rbegin:"<<*it2<<endl;
    it2++;
    cout<<"v rbegin++:"<<*it2<<endl;
    //Using iterator in loop
    cout<<"Using iterator in loop v:";
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"Using auto iterator in loop v:";
    //Using itreator as auto
    //auto assinges data type automaticaly
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    //using for each loop
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    //erase
    v.erase(v.begin());//erase 1 element
    v.erase(v.begin(),v.begin()+2);//erases 3 element
    
    //insert
    v.insert(v.begin(),200);//1 element
    v.insert(v.begin(),2,20);//inserts 2 20s in v begin

    cout<<"v size:"<<v.size()<<endl;

    v.pop_back();
    
    //swap
    v3.swap(v4);
    
}

void List(){
    //doubly linked list is mantained for list
    //inserting in the front is very cheap then vector
    
    list<int> ls;
    ls.push_back(2);
    cout<<"ls.push_back(2):";
    for(int i:ls)cout<<i<<" ";
    cout<<endl;
    ls.emplace_back(3);
    cout<<"ls.emplace_back(3):";
    for(int i:ls)cout<<i<<" ";
    cout<<endl;
    ls.push_front(5);
    cout<<"ls.push_front(5):";
    for(int i:ls)cout<<i<<" ";
    cout<<endl;
    ls.emplace_front();
    cout<<"ls.emplace_front():";
    for(int i:ls)cout<<i<<" ";
    cout<<endl;
    //rest same as vector
}

void Deque(){
    deque<int>dq;
    dq.push_back(1);      // [1]
    dq.emplace_back(2);   // [1, 2]
    dq.push_front(4);     // [4, 1, 2]
    dq.emplace_front(3);  // [3, 4, 1, 2]

    dq.pop_back();        // removes 2 → [3, 4, 1]
    dq.pop_front();       // removes 3 → [4, 1]

    int a=dq.back();
    int b=dq.front();
    cout<<a<<" "<<b;
}

void Stack(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.emplace(5);

    cout<<"top:"<<st.top()<<endl;
    st.pop();
    cout<<"new top after pop:"<<st.top()<<endl;
    cout<<"st size:"<<st.size()<<endl;
    cout<<"is it empty:"<<st.empty()<<endl;
    stack<int>st1,st2;
    st1.swap(st2);
}

void Queue(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(3);
    q.back()+=2;
    cout<<"Adding 2 to the back:"<<q.back()<<endl;
    cout<<"front:"<<q.front()<<endl;

    q.pop();
    cout<<"After poping from queue  front:"<<q.front();

}

void Priority_Queue(){
    priority_queue<int>pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10);

    cout<<"pq-top laso max-heap-top:"<<pq.top();
    pq.pop();
    cout<<" after pop pq-top:"<<pq.top()<<endl;
    
    priority_queue<int,vector<int>,greater<int>>pq2;

    pq2.push(5);
    pq2.push(2);
    pq2.push(8);
    pq2.emplace(18);
    cout<<"min priority queue = minheap:"<<pq2.top();
}


int main(){
    // Pair();
    // Vector();
    // List();
    // Deque();
    // Stack();
    // Queue();
    Priority_Queue();
    return 0;
}