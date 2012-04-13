// recovers files by getting information of start and end points from files "StarPosition" and "EndPosition" 
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

long start=-1,start1 = -1, end=-1, size;	// start= starting of jpeg, end=end of jpeg, size= size of jpeg file (end-start)
FILE *fpi,*fpo,*fpStart, *fpEnd;				//fpi is input file pointer, fpo is output file pointer
string baseName="pdf_recovered", name;					//output filename = <basename>+<nm++>.jpg
char lastName[100];		
int nm;

void copy(long Start, long Size);		// copies data between header and footer
void generateName();				// generates output file names
void recover();



int main(int argc, char *argv[]){

	if(argc!=2){
		cerr<<"usage: ./recover <image file> <type>"<<endl;
		return -1;
	}

	fpi = fopen(argv[1], "r");
	if(fpi==NULL){
		cerr<<"error opening file :"<<argv[1]<<endl;
		return -1;
	}

	fpStart = fopen("headerpospdf", "r");
	if(fpStart==NULL){
		cerr<<"error opening file :Headerpos.txt"<<endl;
		return -1;
	}


	fpEnd 	= fopen("footerpospdf", "r");
	if(fpEnd==NULL){
		cerr<<"error opening file :footerpos.txt"<<endl;
		return -1;
	}

	if(feof(fpStart) || feof(fpEnd)){
		cerr<<"no position recorded"<<endl;
		return -1;
	}

	
	recover();	
	//cp a.pdf pdf_recovered;
	fclose(fpStart);
	fclose(fpEnd);
	fclose(fpi);
	return 0;
}

void recover(){

	//short flag;
	//flag = fscanf(fpStart,"%ld",&start1);
	while((fscanf(fpStart,"%ld",&start1) != -1) && (fscanf(fpEnd,"%ld",&end) != -1)){
		while((end < start1) && (fscanf(fpEnd,"%ld",&end) != -1));	//removes footers above header from 											//consideration

			
		while(start1 < end){						// seeks nearest header above the footer
			start = start1;
			if((fscanf(fpStart,"%ld",&start1)) == -1)
				break;
		}
		size = end - start;
		if(size > 0)

			copy(start, size);
	}
}

void copy(long Start, long Size){				// copies recovered file to output file

	generateName();

	fpo = fopen(name.c_str(), "w");					
	fseek(fpi, 8, SEEK_SET);
	for(long i=Size; i!=0; i--)
		fputc(fgetc(fpi), fpo);
	fclose(fpo);
}

void generateName(){


 
	nm++;
	sprintf(lastName, "%d.pdf",nm);
	name = baseName + lastName;



}
	
