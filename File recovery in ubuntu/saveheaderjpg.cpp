#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

unsigned char h[10];						//data from iamge that has to be checked
unsigned char H[10] = {0xff, 0xd8, 0xff, 0xe0, 0x00, 0x10, 0x4a, 0x46, 0x49, 0x46};		// header of concerned file

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
	freopen("headerposjpg", "w",stdout);		//file to store starts
	Start();					// reads and stores starting point of jpegs
	if (start == -1){
		cerr<<"couldn't find start"<<endl;
		exit(-1);
	}
		
}

	
bool Headercheck(){					//checks if stream is header
	if(!memcmp(h, H, 10))
		return true;
	else
		return false;
}


							// reads and stores starting point of jpegs
void Start(){
	while(fread(h, 1, 10, fpi)==10){
		
	
	if(Headercheck()){
		fseek(fpi, -10, SEEK_CUR);
		start = ftell(fpi);
		cout<<start<<endl;
		fseek(fpi, 10, SEEK_CUR);
	
	}
	else
		fseek(fpi, -9, SEEK_CUR);
		
	
	}

}
	



