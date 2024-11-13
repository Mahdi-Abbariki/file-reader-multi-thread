#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <pthread.h>

#define NUM_OF_CUNK 50

using namespace std;


ifstream file;
mutex mtxFile;


struct ReadFileArgs {
    int startP;
    int endP;
};

void * ReadFile(void *argsv)
{


    ReadFileArgs args = *((ReadFileArgs *)argsv);

    printf("name: %s\n", args.startP);
    printf("age: %d\n", args.endP);

    /*
    if(args.startP > args.endP){ //validate input args
        cout << "start of file pointer should be smaller than end of file pointer" << endl;
        exit(1);
    }
    if(args.startP < 0){ //validate input args
        cout << "start of file pointer should be greater than 0" << endl;
        exit(1);
    }

    int len = args.endP - args.startP;
    string toSearch = "";
    char c;



    //critical
    mtxFile.lock();
    file.seekg(args.startP);
    for(int i=0; i < len; i++){
        file.get(c);
        cout<<c<<endl;
        toSearch += c;
    }
    mtxFile.unlock();
    //critical

    cout << toSearch;
*/

}


int main()
{

    /*file.open("test.txt",ios::in);
    if(!file.is_open()){// cehck file
        cout << "There is an Error reading from File specified" << endl;
        exit(1);
    }*/


    pthread_t ptid;

    ReadFileArgs args;
    args.endP = 10;
    args.startP = 1;


    pthread_create(&ptid,NULL,&ReadFile,(void *)&args);



    pthread_join(ptid, NULL);

    file.close();
    return 0;
}
