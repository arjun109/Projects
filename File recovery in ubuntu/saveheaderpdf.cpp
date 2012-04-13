#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

unsigned char h[7];					//data from iamge that has to be checked
unsigned char H[7] = {0x25, 0x50, 0x44, 0x46, 0x2d, 0x31, 0x2e};	// header of concerned file

long start=-1, end=-1;			// start= starting of pdf, end=end of pdf, size= size of pdf file (end-start)
FILE *fpi, *fpStart;				//fpi is input file pointer

bool Headercheck();

void Start();

void record();




int main(int argc, char* argv[]){
	
	if(argc!=2){
		cerr<<"usage: ./record <image file>"<<endl;
		return -1;
	}
	
	fpi = fopen(argv[1], "r");
	if(fpi==NULL){
		cerr<<"error opening file :"<<argv[1]<<endl;
		return -1;
	}

	
	record();
	fclose(fpi);
	return 0;
}

void record(){
	freopen("headerpospdf", "w",stdout);		//file to store starts
	Start();					// reads and stores starting point of pdf
	if (start == -1){
		cerr<<"couldn't find start"<<endl;
		exit(-1);
	}
		
}

	
bool Headercheck(){					//checks if stream is header
	if(!memcmp(h, H, 7))
		return true;
	else
		return false;
}


							// reads and stores starting point of pdf
void Start(){
	while(fread(h, 1, 7, fpi)==7){
		
	
	if(Headercheck()){
                 
		fseek(fpi, -7, SEEK_CUR);
		start = ftell(fpi);
		cout<<start<<endl;
		fseek(fpi, 7, SEEK_CUR);
	
	}
	else
		fseek(fpi, -6, SEEK_CUR);

		
	
	}

}
	



