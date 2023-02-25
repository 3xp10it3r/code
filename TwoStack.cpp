#include<bits/stdc++.h>
using namespace std;

class TwoStacks
{

	private:
		int *arr;
		int maxSize;
		int size1;
		int size2;
		int top1;
		int top2;

	public:
		TwoStacks(int sz=10)
		{
			arr = new int[sz];
			top1 = -1;
			top2 = sz;
			size1=0;
			size2=0;
			maxSize = sz;
		}

		bool full(){
			return top1+1 == top2;
		}

		void push1(int value)
		{
			if(full())
			{
				cout<<"Overflow"<<endl;
				return;
			}
			else
			{
				arr[++top1] = value;
				size1++;
			}
		}

		void push2(int value)
		{
			if(full())
			{
				cout<<"Overflow"<<endl;
				return;
			}
			else
			{
				arr[--top2]=value;
				size2++;
			}
		}

		bool empty1()
		{
			if(size1) return false;
			return true;
		}

		bool empty2()
		{
			if(size2) return false;
			return true;
		}

		void pop1()
		{
			if(empty1())
			{
				cout<<"Underflow"<<endl;
				return;
			}
			else
			{
				size1--;
				arr[top1--] = -1;
			}
		}

		void pop2()
		{
			if(empty2())
			{
				cout<<"Underflow"<<endl;
				return;
			}
			else
			{
				size2--;
				arr[top2++] = -1;
			}
		}		

		int getTop1()
		{
			if(empty1())
			{
				cout<<"Underflow"<<endl;
				return -1;
			}
			else
			{
				return arr[top1];
			}
		}

		int getTop2()
		{
			if(empty2())
			{
				cout<<"Underflow"<<endl;
				return -1;
			}
			else
			{
				return arr[top2];
			}
		}

		void print()
		{
			for(int i = 0 ; i < maxSize; i++)
			{
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};

int main(){
	TwoStacks ts = TwoStacks(10);
	ts.push1(5);
	ts.pop1();
	ts.push1(10);
	ts.push2(20);
	ts.push1(10);
	ts.push2(20);
	ts.push1(10);
	ts.push2(20);
	ts.push1(10);
	ts.push2(20);
	ts.push1(10);
	ts.push2(20);
	ts.push1(10);
	ts.push2(20);
	ts.pop1();
	ts.pop2();
	ts.pop1();
	ts.pop2();
	ts.pop1();
	ts.pop2();
	ts.pop1();
	ts.pop2();
	ts.pop1();
	ts.pop2();
	ts.pop1();
	ts.pop2();
	cout<<ts.full()<<endl;
	ts.print();
	cout<<"s";
	return 0;
}