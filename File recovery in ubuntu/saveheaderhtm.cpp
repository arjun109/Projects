#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

unsigned char h[16];						//data from iamge that has to be checked
unsigned char H[16] = {0x3c, 0x21, 0x44, 0x4f, 0x43, 0x54, 0x59, 0x50, 0x45, 0x20, 0x48, 0x54, 0x4d, 0x4c, 0x20, 0x50};	// header of concerned file

long start=-1, end=-1;			// start= starting of jpeg, end=end of jpeg, size= size of jpeg file (end-start)
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
	freopen("headerposhtm", "w",stdout);		//file to store starts
	Start();					// reads and stores starting point of jpegs
	if (start == -1){
		cerr<<"couldn't find start"<<endl;
		exit(-1);
	}
		
}

	
bool Headercheck(){					//checks if stream is header
	if(!memcmp(h, H, 16))
		return true;
	else
		return false;
}


							// reads and stores starting point of jpegs
void Start(){
	while(fread(h, 1, 16, fpi)==16){
		
	
	if(Headercheck()){
		fseek(fpi, -16, SEEK_CUR);
		start = ftell(fpi);
		cout<<start<<endl;
		fseek(fpi, 16, SEEK_CUR);
	
	}
	else
		fseek(fpi, -15, SEEK_CUR);
		
	
	}

}
	



