//============================================================================
// Name        : naive.cpp
// Author      : Pruthviraj Prashant Pardeshi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include <cstring>
#include<iomanip>
using namespace std;
class record
{
public:
	float getAge() const {
		return age;
	}

	void setAge(float age) {
		this->age = age;
	}

	const string& getQual() const {
		return qual;
	}

	void setQual(const string& qual) {
		this->qual = qual;
	}

	const string& getWorkType() const {
		return work_type;
	}

	void setWorkType(const string& workType) {
		work_type = workType;
	}

	float getXper() const {
		return xper;
	}

	void setXper(float xper) {
		this->xper = xper;
	}
record()
{
	age=0;
	xper=0;
	qual='\0';
	work_type='\0';
}
private:

	float age;
	float xper;
	string qual;
	string work_type;
};

float ageMean(record rec[],float cnt)
{
	float total=0;
	for(int i=0;i<cnt;i++)
	{
		total+=rec[i].getAge();
	}
	float mean=float(total)/float(cnt);
	return mean;
}

float xperMean(record rec[],float cnt)
{
	float total=0;
	for(int i=0;i<cnt;i++)
	{
		total+=rec[i].getXper();
	}
	float mean=float(total)/float(cnt);
	return mean;
}

float ageVar(record rec[],float cnt)
{
	float vari=0;
	float AgeMean= ageMean(rec,cnt);
		for(int i=0;i<cnt;i++)
		{
			float Age=rec[i].getAge();
			vari+=pow((Age-AgeMean),2);
		}
		vari=float(vari)/float((cnt-1));
		return vari;
}

float xperVar(record rec[],float cnt)
{
	float vari=0;
	float XperMean=xperMean(rec,cnt);
		for(int i=0;i<cnt;i++)
		{
			float Xper=rec[i].getXper();
			vari+=pow((Xper-XperMean),2);
		}
		vari=float(vari)/float(cnt-1);
		return vari;
}

float agePro(record rec[],float mean,float var,float tarAge)
{
	float prob;
	prob = (float(1)/float(sqrt(2*3.14*var)))*(float(exp(-(float(tarAge-mean)/float(2*var)))));
	return prob;
}

float xperPro(record rec[],float mean,float var,float tarXper)
{
	float prob;
	prob = (1/float(sqrt(2*3.14*var)))*(float(exp(-(float(tarXper-mean)/float(2*var)))));
	return prob;
}

float qualPro(record rec[],float cnt,string tarQual)
{

		static float bcnt=0,mcnt=0,pcnt=0;
		for(int i=0;i<cnt;i++)
		{
			if(rec[i].getQual()=="BTech"||rec[i].getQual()=="Btech")
			{
				bcnt++;
			}
			else if(rec[i].getQual()=="MTech"||rec[i].getQual()=="Mtech")
			{
				mcnt++;
			}
			else
			{
				pcnt++;
			}
		}

		float qualprob;
		if(tarQual=="MTech"||tarQual=="Mtech")
		{
			qualprob=float(mcnt)/float(cnt);
		}
		else if(tarQual=="BTech"||tarQual=="Btech")
		{
			qualprob=float(bcnt)/float(cnt);
		}
		else
		{
			qualprob=float(pcnt)/float(cnt);
		}

		return qualprob;
}
int main()

{
	static int n;
	record rec[10],con[10],ser[10],res[10];
	cout<<"\nEnter the number of records you want to create\n";
	cin>>n;
	string wtmp,qtmp;
	float atmp=0,xtmp=0;
	static int ccnt=0,scnt=0,rcnt=0;
	for(int i=0;i<n;i++)
	{

	lab:cout<<"\nEnter the work type of the person "<<i+1<<"\n";
		cin>>wtmp;
		if(wtmp=="Consultancy")
		{
			rec[i].setWorkType(wtmp);
			con[ccnt].setWorkType(wtmp);
			cout<<"\nEnter the age of the person "<<i+1<<"\n";
			cin>>atmp;
			rec[i].setAge(atmp);
			con[ccnt].setAge(atmp);
  		cout<<"\nEnter the experience of the person "<<i+1<<"\n";
			cin>>xtmp;
			rec[i].setXper(xtmp);
			con[ccnt].setXper(xtmp);

			cin>>qtmp;
		{
			rec[i].setQual(qtmp);
			con[ccnt].setQual(qtmp);
			ccnt++;
		}
		else if(wtmp=="Service")
				{
					rec[i].setWorkType(wtmp);
					ser[scnt].setWorkType(wtmp);

					cout<<"\nEnter the age of the person "<<i+1<<"\n";
					cin>>atmp;
					rec[i].setAge(atmp);
					ser[scnt].setAge(atmp);

					cout<<"\nEnter the experience of the person "<<i+1<<"\n";
					cin>>xtmp;
					rec[i].setXper(xtmp);
					ser[scnt].setXper(xtmp);

          cout<<"\nEnter the qualification of the person "<<i+1<<"\n";
					cin>>qtmp;
					rec[i].setQual(qtmp);
					ser[scnt].setQual(qtmp);
					scnt++;

				}
		else if(wtmp=="Research")
				{
					rec[i].setWorkType(wtmp);
					res[rcnt].setWorkType(wtmp);

					cout<<"\nEnter the age of the person "<<i+1<<"\n";
					cin>>atmp;
					rec[i].setAge(atmp);
					res[rcnt].setAge(atmp);

					cout<<"\nEnter the experience of the person "<<i+1<<"\n";
					cin>>xtmp;
					rec[i].setXper(xtmp);
					res[rcnt].setXper(xtmp);

					cout<<"\nEnter the qualification of the person "<<i+1<<"\n";
					cin>>qtmp;
					rec[i].setQual(qtmp);
					res[rcnt].setQual(qtmp);
					rcnt++;
				}
		else
		{
			cout<<"\nInvalid work type. Please try again\n";
			goto lab;
		}
	}
	cout<<"\nNow enter the target attributes";
	record target;
	float tAge,tXper;
	cout<<"\nEnter the target age:";
	cin>>tAge;
	target.setAge(tAge);
	cout<<"\nEnter the target experience:";
	cin>>tXper;
	target.setXper(tXper);
	string tQual;
  cout<<"\nEnter the target qualification:";
	cin>>tQual;
	target.setQual(tQual);

	cout<<"\nNow,calculating means and variances";
  cout<<"\nGoing for age means";

	float ageConMean;
	ageConMean=ageMean(con,ccnt);
	cout<<"\nThe mean of ages of consultants is:"<<ageConMean;

	float ageResMean;
	ageResMean=ageMean(res,rcnt);
	cout<<"\nThe mean of ages of researchers is:"<<ageResMean;

	float ageSerMean;
	ageSerMean=ageMean(ser,scnt);
	cout<<"\nThe mean of ages of service men is:"<<ageSerMean;

  cout<<"\nGoing for experience means";

	float xperConMean;
	xperConMean=xperMean(con,ccnt);
	cout<<"\nThe mean of experiences of consultants is:"<<xperConMean;

	float xperResMean;
	xperResMean=xperMean(res,rcnt);
	cout<<"\nThe mean of experiences of researchers is:"<<xperResMean;

	float xperSerMean;
	xperSerMean=xperMean(ser,scnt);
	cout<<"\nThe mean of experiences of service men is:"<<xperSerMean;

  cout<<"\nGoing for age variances";
	float ageConVar;
	ageConVar=ageVar(con,ccnt);
	cout<<"\nThe variance of ages of consultants is:"<<ageConVar;

	float ageResVar;
	ageResVar=ageVar(res,rcnt);
	cout<<"\nThe variance of ages of researchers is:"<<ageResVar;

	float ageSerVar;
	ageSerVar=ageVar(ser,ccnt);
	cout<<"\nThe variance of ages of service men is:"<<ageSerVar;

  cout<<"\nGoing for experience variances";
	float xperConVar;
	xperConVar=ageVar(con,ccnt);
	cout<<"\nThe variance of experience of consultants is:"<<xperConVar;

	float xperResVar;
	xperResVar=ageVar(res,rcnt);
	cout<<"\nThe variance of experience of researchers is:"<<xperResVar;

	float xperSerVar;
	xperSerVar=ageVar(ser,ccnt);
	cout<<"\nThe variance of experience of service men is:"<<xperSerVar;

  cout<<"\nFinding probabilities";
  static float conProb=0,resProb=0,serProb=0;
  
  conProb = float(ccnt)/float(n);
  cout<<"\nP(C)="<<conProb<<fixed<<setprecision(3);
  
  resProb = float(rcnt)/float(n);
  cout<<"\nP(R)="<<resProb<<fixed<<setprecision(3);

  serProb = float(scnt)/float(n);
  cout<<"\nP(S)="<<serProb<<fixed<<setprecision(3);
  
  cout<<"\nGoing for age probabilities";
  float ageConProb;
  ageConProb = agePro(con,ageConMean,ageConVar,tAge);
  cout<<"\nageConProb="<<ageConProb;

float ageResProb;
ageResProb = agePro(res,ageResMean,ageResVar,tAge);
cout<<"\nageResProb="<<ageResProb;

float ageSerProb;
ageSerProb = agePro(ser,ageSerMean,ageSerVar,tAge);
cout<<"\nageSerProb="<<ageSerProb;

cout<<"\nGoing for experience probabilities";
float xperConProb;
xperConProb = xperPro(con,ageConMean,ageConVar,tXper);
cout<<"\nxperConProb="<<xperConProb;

float xperResProb;
xperResProb = xperPro(res,xperResMean,xperResVar,tXper);
cout<<"\nxperResProb="<<xperResProb;

float xperSerProb;
xperSerProb = xperPro(ser,xperSerMean,xperSerVar,tXper);
cout<<"\nxperSerProb="<<xperSerProb;

cout<<"\nGoing for quality probabilities";

float qualConProb;
qualConProb=qualPro(con,ccnt,tQual);
cout<<"\nqualConProb="<<qualConProb;

float qualResProb;
qualResProb=qualPro(res,rcnt,tQual);
cout<<"\nqualResProb="<<qualResProb;

float qualSerProb;
qualSerProb=qualPro(ser,scnt,tQual);
cout<<"\nqualSerProb="<<qualSerProb;

cout<<"\nGoing for final posterior probability";
float conPost,serPost,resPost,evidence;
conPost=conProb*ageConProb*xperConProb*qualConProb;
serPost=serProb*ageSerProb*xperSerProb*qualSerProb;
resPost=resProb*ageResProb*xperResProb*qualResProb;
evidence = conPost+serPost+resPost;
cout<<"\nEvidence is"<<evidence;

conPost=float(conPost)/float(evidence);
serPost=float(serPost)/float(evidence);
resPost=float(resPost)/float(evidence);

cout<<"\nFinal posterior probability for consultancy is \t"<<conPost;
cout<<"\nFinal posterior probability for research is \t"<<resPost;
cout<<"\nFinal posterior probability for service is \t"<<serPost;

if(conPost>serPost&&conPost>resPost)
{
	cout<<"\n###RESULT=Prediction is that work type would be Consultancy ###";
}
else if(serPost>conPost&&serPost>resPost)
{
	cout<<"\n###RESULT=Prediction is that work type would be Service ###";
}
else
{
	cout<<"\n###RESULT=Prediction is that work type would be Research ###";
}

	cout<<"\nThe entered values are as follows\n";
	cout<<"---WorkType----|---Age---|---Exp----|---Qual---";
	cout<<"\n_____________________________________________";
	cout<<"\nConsultancy    |";
	for(int i=0;i<ccnt;i++)
	{
		cout<<"\n"<<"               "<<"|   "<<con[i].getAge()<<"    |"<<"    "<<con[i].getXper()<<"    |"<<"   "<<con[i].getQual()<<"   ";
	}
	cout<<"\n_____________________________________________";
	cout<<"\nResearch       |";
	for(int i=0;i<rcnt;i++)
		{
			cout<<"\n"<<"               "<<"|   "<<res[i].getAge()<<"    |"<<"    "<<res[i].getXper()<<"    |"<<"   "<<res[i].getQual()<<"   ";
		}
	cout<<"\n_____________________________________________";
	cout<<"\nService        |";
		for(int i=0;i<scnt;i++)
			{
				cout<<"\n"<<"               "<<"|   "<<ser[i].getAge()<<"    |"<<"    "<<ser[i].getXper()<<"    |"<<"   "<<ser[i].getQual()<<"   ";
			}



return 0;
}
