#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

class DaynamicFloats {

private :
	int s;
	float *p;
	
public :
	DaynamicFloats()
	{
	s=0;
	p=NULL;
	}

	~DaynamicFloats()
	{
	if (p!=NULL){delete p;}
	}

	DaynamicFloats(const DaynamicFloats &d)
	{
	s=d.s;
	if (s>0){
	p= new float [s];
	for (int i=0; i<s; i++){
	p[i]=d.p[i];
	}
	}
	else {p=NULL;}
	}
	
	int GetSize()	{
		return s;	}

	void SetSize(int news)	{
		if (s==0){
		s=news;
		p = new float [s];
		return;		}

		float *t = new float [news];
		int m=s;
		if(s>news){ m=news; }
		for (int i=0; i<m; i++){ t[i]=p[i]; }
		delete []p;
		p=t;
		s=news;	}

	float GetEl(int i){
		if (i>s) { cout << "ERROR! Index is bigger than array's width !!!" << endl;
		return 0; }
		else{ return p[i];} }

	void SetEL (int i,float element){
		if (i>s) { cout << "ERROR! Index is bigger than array's width !!!" << endl; }
		else { p[i]=element; }       }


	void ADD(float element){
		SetSize(s+1);
		p[s-1]=element;    }

	void RemoveEl(int i){
	p[i]=0;	}


	void PrintArray () {
		for (int i=0; i<s; i++) {
		cout << p[i] << endl ;
		} 
		cout << "----------------------" << endl;
	}
	
	int FindEl(float element) {
		    for (int i=0; i<s; i++){
			if (p[i]==element)
			{	return i; } 
			else {return 999;}} }

	double SumArray () {
		double sum=0;
		for (int i=0; i<s; i++){
		sum+=p[i];
		}	
		return sum;	}

	void RemoveArray () {
		delete []p;}

	void FillArray() {
		for (int i=0; i<s; i++){
		p[i]=rand();
		}	}
};