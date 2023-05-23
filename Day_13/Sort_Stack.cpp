#include <bits/stdc++.h> 

void insert(stack<int>&st,int num)
{
	if(st.size()==0 || st.top() < num)
	{
		st.push(num);
		return;
	}
	int x = st.top();
	st.pop();
	insert(st,num);
	st.push(x);
}

void sortStack(stack<int> &st)
{
	if(st.size()==0)
		return;
	int num = st.top();
	st.pop();
	sortStack(st);
	insert(st,num);
}
