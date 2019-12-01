#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;
map<string,string> NAT_items;
map<string,string>::iterator match;

int check_NAT(string flow)
{

    string flow_port, flow_IP;
    int position = flow.find(':');

    flow_IP = flow.substr(0,position);
    flow_port = flow.substr(position+1);

    //Direct match
    match = NAT_items.find(flow);
    if ( match != NAT_items.end())
    {
        cout<<flow<<" -> "<<match->second<<endl;
        return 0;
    }

    //Any IP to a specific port match
    string temp_for_IP = "*:" + flow_port;
    match = NAT_items.find(temp_for_IP);
    if( match != NAT_items.end())
    {
        cout<<flow<<" -> "<<match->second<<endl;
        return 0;

    }

    //Any port to a specific IP match
    string temp_for_port = flow_IP + ":*";
    match = NAT_items.find(temp_for_port);
    if( match != NAT_items.end())
    {
        cout<<flow<<" -> "<<match->second<<endl;
        return 0;

    }

    //If no kind of match is found
    cout<<"No NAT match for "<<flow<<endl;
    return 0;

}


int main()
{
    std::ifstream NAT_file;
    std::ifstream FLOW_file;
    vector<string> FLOW_items;

    int ret_val = 0;
    string temp_line, temp2_line;

    NAT_file.open("NAT.txt");
    FLOW_file.open("FLOW.txt");

    //check if files can be opened
    if(!NAT_file)
    {
        cerr<<"Problem with opening the NAT file"<<endl;
        return 1;
    }
    if(!FLOW_file)
    {
        cerr<<"Problem with opening the FLOW file"<<endl;
        return 1;
    }

    //Get all data from NAT file into a dictionary map
    while(getline(NAT_file, temp_line))
    {
        int x = temp_line.find(',');
        temp2_line = temp_line.substr(0, x);
        NAT_items[temp2_line] = temp_line.substr(x+1);
    }
    
    //Get all data from FLOW file into a vector
    while(getline(FLOW_file, temp_line))
    {
        FLOW_items.push_back(temp_line);
    }

    //check for match
    for( auto f : FLOW_items )
    {
        ret_val = check_NAT(f);
    }

    return 0;
}
