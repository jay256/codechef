#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Interval{
    int start;
    int end;
};

bool compareInterval(Interval i1, Interval i2){  
	return (i1.start < i2.start)? true: false; 
}

void mergeIntervals(vector<Interval>& intervals){
	if (intervals.size() <= 0)
		return;
	sort(intervals.begin(), intervals.end(), compareInterval);
	int bombpos=0,result=0;
	for(int i=0;i<intervals.size();i++){
		if(i==0){
			bombpos=intervals[i].start;
			result+=1;
		}
		else{
			/*if(intervals[i].start==intervals[i-1].start){
				if(i-1==0){
					result+=1;
				}
				continue;
			}
			else if(intervals[i].start>intervals[i-1].start && intervals[i].start<=intervals[i-1].end){
				bombpos=intervals[i].start;
				result+=1;
			}
			else if(intervals[i].start>intervals[i-1].end){
				bombpos=intervals[i].start;
				result+=1;
			}*/
			if(intervals[i].start==intervals[i-1].start)
				continue;
			else if(intervals[i].start>intervals[i-1].start){
				if(intervals[i].start<=intervals[i-1].end){
					bombpos=intervals[i].start;
					continue;
				}
				else if(intervals[i].start>intervals[i-1].end){
					bombpos=intervals[i].start;
					result+=1;
				}
			}
		}
	}
	cout << result << endl;
	return;
}

int main(){
	int T,N,i;
	cin >> T;
	while(T>0){
		cin >> N;
		Interval intervals[N];
		i=0;
		while(i<N){
			cin >> intervals[i].start;
			cin >> intervals[i].end;
			i++;		
		}
		vector<Interval> intvls(intervals, intervals+sizeof(intervals)/sizeof(Interval));
		mergeIntervals(intvls);
		T--;	
	}
	return 0;
}
