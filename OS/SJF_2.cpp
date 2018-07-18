#include<iostream>

using namespace std;

struct SJF
{
	float *burst,*arrival,*Start,*Finish;
	int n;
};

void Insertion_Sort(SJF& F)
{
	float temp;
	
	for(int i=1;i<F.n;i++)
	{
		for(int j=i;j>=1;j--)
		{
			if(F.arrival[j]<F.arrival[j-1])
			{
				temp=F.arrival[j];
				F.arrival[j]=F.arrival[j-1];
				F.arrival[j-1]=temp;
				
				temp=F.burst[j];
				F.burst[j]=F.burst[j-1];
				F.burst[j-1]=temp;
			}
			else
				break;
		}
	}
}

void getdata(SJF &F)
{
			
	cout<<"Enter the no. of Processes \n";
	cin>>F.n;
			
	F.burst=new float[F.n];
			
	cout<<"Enter the burst time of Processes \n";
	for(int i=0;i<F.n;i++)
	cin>>F.burst[i];
			
	F.arrival=new float[F.n];
			
	cout<<"Enter the arrival time of Processes \n";
	for(int i=0;i<F.n;i++)
	cin>>F.arrival[i];
		}

void sjf(SJF &F)
{
	
	float sum=0,temp;
	float Time;
	int j=1,val,i;
	
	F.Start=new float[F.n];
	F.Finish=new float[F.n];
	
	F.Start[0]=0;
	F.Finish[0]=F.burst[0];
	sum=sum+F.burst[0];
	Time=sum;
	
	while(j<F.n)
	{
		val=j;
		F.Start[j]=F.Finish[j-1];
		temp=F.burst[j];
		for(i=j+1;i<F.n;i++)
		{
			if(F.burst[i]<=temp&&F.arrival[i]<=Time)
			{
				val=i;
			}
		}
			if(val!=j)
			{
				temp=F.arrival[val];
				F.arrival[val]=F.arrival[j];
				F.arrival[j]=temp;
				
				temp=F.burst[val];
				F.burst[val]=F.burst[j];
				F.burst[j]=temp;
			}
			
			sum=sum+F.burst[j];
			Time=sum;
			F.Finish[j]=sum;
			
	
		j++;
	}


	
/*	for(int i=0;i<F.n;i++)
	{	if(sum>=F.arrival[i])
		{
			sum=sum+F.burst[i];
			F.Finish[i]=sum;
			F.Start[i+1]=F.Finish[i];
		}
		else
		{
			F.Finish[i]=F.arrival[i]+F.burst[i];
			sum=F.Finish[i];
			F.Start[i]=F.arrival[i];
		}
	}	
*/	
}

void Print(SJF &F)
{
	float wait,turn;
	float sum=0;
	
	for(int i=0;i<F.n;i++)
	{
		wait=F.Start[i]-F.arrival[i];
		cout<<"Waiting Time of Process "<<i+1<<" :"<<wait<<"\n";
		sum=sum+wait;
	}
	
	cout<<"\nAverage Waiting time : "<<sum/F.n<<"\n\n";
	sum=0;
	
	for(int i=0;i<F.n;i++)
	{
		turn=F.Finish[i]-F.arrival[i];
		cout<<"Turnaround Time of Process "<<i+1<<" :"<<turn<<"\n";
		sum=sum+turn;
	}
	
	cout<<"\nAverage Turnaround time : "<<sum/F.n<<"\n\n";
	
}
		
int main()
{
	SJF F;
	getdata(F);
	Insertion_Sort(F);	
	sjf(F);
	for(int i=0;i<F.n;i++)
		cout<<F.burst[i]<<" ";
		cout<<"\n";
	
	for(int i=0;i<F.n;i++)
		cout<<F.arrival[i]<<" ";
		cout<<"\n";
		
	for(int i=0;i<F.n;i++)
		cout<<F.Start[i]<<" ";
		cout<<"\n";
	
	for(int i=0;i<F.n;i++)
		cout<<F.Finish[i]<<" ";
		cout<<"\n";
		
	Print(F);
	
	return 0;
	
}
