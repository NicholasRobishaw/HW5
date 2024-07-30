#include "main.h"
#include "Prefix_Trie.h"

using namespace std;

#ifndef MAIN_CPP
#define MAIN_CPP

int main(int argc, char* argv[]){
    time_t stop_Watch = 0;
    Prefix_Trie my_Trie;
    int nodes = 0, hits = 0;
    int queryNum = 0;
    bool partB = false;
    
    time(&stop_Watch);
    cout << "Program Start at: " << ctime(&stop_Watch) << endl;

    //./my_program human.txt <query size> 

    // check if the program has the appropriate number of parameter
    // create error handler for no input file argument
    if( argc < 2 ){
        cout << "Error please input the correct command in\n Program End";
        return 1;
    }


    // check for problem A or B
    cout << "Argv 1 = " << argv[1] << endl;
    cout << "Argv 2 = " << argv[2] << endl;
    cout << "Argv 3 = " << argv[3] << endl;
    

    if(my_Trie.file_reader(argv[1])){
        cout << "Successful read query completion" << endl;
    }

    else{
        cout << "Unsuccessful read query completion" << endl;
        return 1;
    }    
    
    //5k, 50k, 100k, and 1M
    if(strcmp(argv[2], "5000") == 0){
        queryNum = 5000;
    }
    else if(strcmp(argv[2], "50000") == 0){
        queryNum = 50000;
    }
    else if(strcmp(argv[2], "100000") == 0){
        queryNum = 100000;
    }
    else if(strcmp(argv[2], "1000000") == 0){
        queryNum = 1000000;
    }
    
    
    // string testStr = "ACTGNNAACCT";
    // cout << " original string: " << testStr << endl;
    // for(int index=0; index < 10; index++){
    //     cout << " mutated string : " << my_Trie.mutate_Fragment(testStr) << endl;
    // }
    
    if(strcmp(argv[3], "B") == 0){
        partB = true;
    }
    
    my_Trie.create_Trie(queryNum, partB);
    
    // search trie
    my_Trie.search_From_Subject(my_Trie.segment);
    
    nodes = my_Trie.get_Nodes();
    hits = my_Trie.get_Hits();
    
    cout << "Number of nodes: " << nodes << endl;
    cout << "Number of hits : " << hits << endl;
    
    
    time(&stop_Watch);
    cout << "Program End at: " << ctime(&stop_Watch) << endl;
    
    return 0;
}

#endif