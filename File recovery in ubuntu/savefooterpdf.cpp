#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

unsigned char f[6];						//data from iamge that has to be checked
unsigned char F[6] = {0x0a, 0x25, 0x25, 0x45, 0x4f, 0x46};		// footer of concerned file
long end=-1;			// start= starting of jpeg, end=end of jpeg, size= size of jpeg file (end-start)
FILE *fpi, *fpEnd;				//fpi is input file pointer


bool Footercheck();

void End();
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

	freopen("footerpospdf", "w",stdout);		//file to store ends
	End();					//reads and stores end point of jpegs
	if (end == -1){
		cerr<<"couldn't find end"<<endl;
		exit(-1);
	}

}



bool Footercheck(){					//checks if stream is footer
	if(!memcmp(f, F, 6))
		return true;
	else 
		return false;
}	
							// reads and stores starting point of jpegs

void End(){							//reads and stores end point of jpegs

				
	if(!fseek(fpi, 0, SEEK_SET))				//sets file position to start
		cerr<<"seekset"<<endl;

	while(fread(f, 1, 6, fpi)==6){
		
			
	if(Footercheck()){
		end = ftell(fpi);

	cout<<end<<endl;
	
	}
	else 
		fseek(fpi, -5, SEEK_CUR);
	
	}
}



