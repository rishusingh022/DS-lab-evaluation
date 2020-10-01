#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//structure  of character and frequency
struct node
{
	int arr_freq;
	char ch;
	node *next;
};
class functions {
    public:
    void show(node **start)
    {
    	cout<<endl;
    	node *x=*start;
    	for(;x!=NULL;x=x->next)
    	{
    		cout<<x->ch<<" "<<x->arr_freq<<" ";
    		
    	}
    }
    void in_order_of_sequence(node **start, int frequency_comp)
    {
    	node *temp1=*start;
    	for(;temp1!=NULL && temp1->arr_freq!=frequency_comp;temp1=temp1->next){}
    	node *last=*start;
    	while(last->next!=NULL)
    	{
    		last=last->next;
    	}
    	if(temp1==NULL)
    	{
    		show(start);
    		return;
    	}
    	node *s=temp1->next;
    	node *temp2=NULL;
    	while(s!=NULL)
    	{
    		if(s->arr_freq==frequency_comp)
    		{
    			temp2=s;
    		}
    		s=s->next;
    	}
    	if(temp2==NULL)
    	{
    		show(start);
    		return;
    	}
    	if(temp2==temp1->next)
    	{
    		show(start);
    		return;
    	}
    	node *t=temp1->next;
    	while(t!=temp2)
    	{
    		if(t->arr_freq!=temp1->arr_freq)
    		{
    			if(t->arr_freq < temp1->arr_freq)
    			{
    				node *s=t->next;
    				temp1->next=s;
    				t->next=*start;
    				*start=t;
    				t=s;
    			}
    			else if(t->arr_freq > temp1->arr_freq)
    			{
    				node *s=t->next;
    				temp1->next=s;
    				last->next=t;
    				t->next=NULL;
    				last=t;
    				t=s;
    			}
    		}
    		else
    		{
    			temp1=t;
    			t=t->next;
    		}
    	}
    	show(start);
    }
    void print_Freq(const std::string&s2,int k, int freq[])
    {
        int i=0;
    	while(i<k)
    	{
    		cout<<s2[i]<<" "<<freq[i]<<" ";
    		i++;
    	}
    }
    void insert_Element(node **start,char b, int a)
    {
    	node *temp=new node();
    	temp->arr_freq=a;
    	temp->ch=b;
    	temp->next=NULL;
    	if(*start==NULL)
    	{
    		*start=temp;
    	}
    	else
    	{
    		node *temp1=*start;
    		for(;temp1->next!=NULL;temp1=temp1->next){}
    		temp1->next=temp;
    	}
    }
};
int main()
{
    functions obj;
	node *start=NULL;
	
	string str;
	getline(cin,str);
	
	int i,j,k=0;
	
	int n;
	cin>>n;
	
	int arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int length=str.length();
	//frequency array creation and initialisation to 1
	int char_freq[length];
	i=0;
	while(i<length)
	{
		char_freq[i]=1;
		i++;
	}
	
	
	string str1=str;
	//loop to calculate the frequency of the chararter in the string
	i=0;
	while(i<length)
	{
		for(j=i+1;j<length;j++)
		{
			if(str[i]==str1[j])
			{
				char_freq[k]=char_freq[k]+1;
				str1[j]='0';
			}
		}
		if(str1[i]!='0')
		{
			k=k+1;
		}
		i++;
	}
	int t=0;
	string str2;
	for(i=0;i<length;i++)
	{
		if(str1[i]!='0')
		{
			str2[t]=str1[i];
			t++;
		}
	}
	cout<<str2;
	obj.print_Freq(str2,k,char_freq);
	for(i=0;i<k;i++)
	{
		obj.insert_Element(&start,str2[i],char_freq[i]);
	}
	i=0;
	while(i<n)
	{
		int m=arr[i];
		obj.in_order_of_sequence(&start,m);
		i++;
	}
}