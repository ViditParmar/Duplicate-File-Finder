#include<iostream>
#include<filesystem>
#include<vector>
#include<map>
#include<fstream>
#include<algorithm>

using namespace std;
namespace fs = filesystem;
class fileinfo{
    public:
    string fname;
    fs::path fpath; 
    uintmax_t fsize; // to store file size in bytes
};
int main(){
    string fp;
    cout<<"enter folder path :";
    getline(cin,fp); // Get folder path from user

    // Check if the path exists
    if(fs::exists(fp)){ 
        cout<<"path exist"<<endl;
    }
    else{
        cout<<"path does not exist"<<endl;
        cout<<"Program terminated"<<endl;
        return 0;
    }

    // Check if the path is a directory
    if(fs::is_directory(fp)){
        cout<<"valid directory"<<endl;
    }
    else{
        cout<<"not a directory"<<endl;
        cout<<"Program terminated"<<endl;
        return 0;
    }
    // Store file information
    vector<fileinfo> files;
    for(const auto& entry : fs::recursive_directory_iterator(fp)){
    
        if(fs::is_regular_file(entry.path())){ 
            fileinfo file;
            file.fname = entry.path().filename().string();
            file.fpath = entry.path();
            file.fsize = fs::file_size(entry.path());
            files.push_back(file);
        }
    }

    // Group files by size
    // Key = file size, Value = files with that size

    map<uintmax_t,vector<fileinfo>> m;
    for(const auto& f : files){
        m[(f.fsize)].push_back(f);
    }
    
    int groupno = 1;
    bool dupfound = false;
    for(const auto& size : m){  
        if(m[size.first].size() > 1){

            vector<vector<int>> groups; // Group duplicate files
              
            for(int i=0;i<m[size.first].size();i++){
                
                for(int j=i+1;j < m[size.first].size();j++){
                    
                    // Open files in binary mode for byte-by-byte comparison
                    ifstream f1(size.second[i].fpath,ios::binary);
                    ifstream f2(size.second[j].fpath,ios::binary);

                    if(!f1) {
                        cout << "file opening error" << endl;
                        cout << "Path: " << size.second[i].fpath << endl;
                        continue;
                    }

                    if(!f2) {
                        cout << "file opening error" << endl;
                        cout << "Path: " << size.second[j].fpath << endl;
                        continue;
                    }

                    bool same = true;
                    char cf1,cf2;

                    while(f1.get(cf1) && f2.get(cf2)){
                        if(cf1 != cf2){
                            same = false;
                            break;
                        }
                    }

                    
                    if(same){

                        // Group identical files 
                        bool added = false;
                        for(auto& group : groups){
                        if(find(group.begin(), group.end(), i) != group.end()){
                            if(find(group.begin(), group.end(), j) == group.end()){
                                group.push_back(j);
                            }
                            added = true;
                            break;
                        }

                        if(find(group.begin(), group.end(), j) != group.end()){
                            if(find(group.begin(), group.end(), i) == group.end()){
                                group.push_back(i);
                            }
                            added = true;
                            break;
                        }
                        }
                        if(!added){
                            groups.push_back({i,j});
                        }

                    }
                }      
            }

            for(const auto& group : groups){
            if(group.size() > 1){
            cout<<"Duplicate group - "<<groupno<<" -"<<endl;
            int fileNumber = 1;
            dupfound = true;
            for(int index : group){
            cout<< "  "<<fileNumber<<")"<<size.second[index].fname << endl;
                fileNumber++;
            }

        // Remove duplicate files

        char choice;
        cout<<endl;
        cout<<"delete all duplicates and keep one file? (y/n): ";
        cin>>choice;

        if(choice == 'y' or choice == 'Y'){
            int keep = group[0]; // keep one file 
            cout<<endl;
            cout<<"Keeping:"<< size.second[keep].fname << endl;
            
            for(int i = 1; i < group.size(); i++){ // Delete all remaining files
                int del = group[i];
                if(fs::remove(size.second[del].fpath)){ // Permanently remove file
                    cout<<"Deleted:"<<size.second[del].fname<<endl;
                }
                else{
                    cout<<"failed to delete"<<size.second[del].fname<<endl;
                }
            }
        }
        cout << endl;
        groupno++;
        }
    }
    }
    }
    if(!dupfound){
        cout<<"NO DUPLICATE FILE FOUND"<<endl;
    }
    cout<<"PROGRAM END"<<endl;
}