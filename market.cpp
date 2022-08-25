#include "market.h"

vector<string> market::removeDupWord(string str) 
{ 
    vector<string> res;
    istringstream ss(str); 
      do { 
        string word; 
        ss >> word; 
        res.push_back(word);
      } while (ss); 
      return res;
} 

map<string, string> market::seperate_input()
{
    map<string, string> temp_info;
    for(int i=0;i<line.size();i++)
    {        
        if(line[i]=="?")
            temp_info.insert(pair<string, string>("?", line[i+1]));
        if(line[i]=="email")
        {
            temp_info.insert(pair<string, string>("email", line[i+1]));
            for(int j=0;j<line[i+1].size();j++)
            {
                if(line[i+1][j]=='@')
                    temp_info.insert(pair<string, string>("@", "@"));
                if (line[i+1][j]=='.')
                    temp_info.insert(pair<string, string>(".", "."));
            }
        }
        if(line[i]=="username")
            temp_info.insert(pair<string, string>("username", line[i+1]));
        if(line[i]=="password")
            temp_info.insert(pair<string, string>("password", line[i+1]));
        if(line[i]=="type")
            temp_info.insert(pair<string, string>("type", line[i+1]));
        if(line[i]=="filePath")
            temp_info.insert(pair<string, string>("filePath",line[i+1]));
        if(line[i]=="productId")
            temp_info.insert(pair<string, string>("productId",line[i+1]));
        if(line[i]=="offerUnitPrice")
            temp_info.insert(pair<string, string>("offerUnitPrice",line[i+1]));
        if(line[i]=="offerAmount")
            temp_info.insert(pair<string, string>("offerAmount",line[i+1]));
       if(line[i]=="discountPercent")
            temp_info.insert(pair<string, string>("discountPercent",line[i+1]));
        if(line[i]=="discountNumber")
            temp_info.insert(pair<string, string>("discountNumber",line[i+1]));
        if(line[i]=="productDetail")
            temp_info.insert(pair<string, string>("productDetail",line[i+1]));
        if(line[i]=="comment" && i!=1)
        {
            string cm;
            for(int j=i+1;j<line.size();j++)
            {
                cm+=line[j]+" ";
            }
            temp_info.insert(pair<string, string>("comment",cm));
        }
        if(line[i]=="productId1")
            temp_info.insert(pair<string, string>("productId1",line[i+1]));
        if(line[i]=="productId2")
            temp_info.insert(pair<string, string>("productId2",line[i+1]));
        if(line[i]=="amount")
            temp_info.insert(pair<string, string>("amount",line[i+1]));
        if(line[i]=="discountCode")
            temp_info.insert(pair<string, string>("discountCode",line[i+1]));
        if(line[i]=="order")
            temp_info.insert(pair<string, string>("order",line[i+1]));
        if(line[i]=="field")
            temp_info.insert(pair<string, string>("field",line[i+1]));
        
   }
    return temp_info;
}

bool market::does_exist(string user_name)
{
for(int i=0;i<HandleInput->return_v_users().size();i++)
    if(HandleInput->return_v_users()[i]->return_username()==user_name )
        return true;
return false;
}

void market::signup()
{
    user *online = online_user();
    if(online != nullptr || HandleInput->is_admin()==true){
        cout << "Bad Request" << endl;
        return;
    }
    if(info.count("email")!=1||info.count("username")!=1||info.count("password")!=1 )
    {
        cout<<"Bad Request"<<endl;
        return;
    }
    if(info.count("@")==1 && info.count(".")==1 && !does_exist(info.find("username")->second))
    {
        if(info.count("type") == 1)
            HandleInput->signup(info.find("email")->second,info.find("username")->second,info.find("password")->second,info.find("type")->second);
        else
            HandleInput->signup(info.find("email")->second,info.find("username")->second,info.find("password")->second,"buyer");
    }
    else
        cout<<"Bad Request"<<endl;                   
}

void open_file_csv_car(vector<string> &name,vector<int> &weight, vector<int> &num_of_seats, vector<int> &num_of_cylinders, vector<int> &engine_capacity, vector<int> &reverse_parking_sensors,string address)
{
	string str;
	ifstream fin;
	fin.open(address);
    
    getline(fin, str, '\n');
	while (getline(fin, str, ','))
	{	 
        name.push_back(str);
		getline(fin, str, ',');
	    weight.push_back(stoi(str));
		getline(fin, str, ',');
		num_of_seats.push_back(stoi(str));
        getline(fin, str, ',');
        num_of_cylinders.push_back(stoi(str));
        getline(fin, str, ',');
        engine_capacity.push_back(stoi(str));
        getline(fin, str, '\n');
        reverse_parking_sensors.push_back(stoi(str));
	}
}

void market::add_cars(vector<string> name,vector<int> weight, vector<int> num_of_seats, vector<int> num_of_cylinders, vector<int> engine_capacity, vector<int> reverse_parking_sensors)
{
    for(int i=0;i<name.size();i++)
    {
        car* new_car = new car(mobiles.size()+i+1,name[i],weight[i],num_of_seats[i],num_of_cylinders[i],engine_capacity[i],reverse_parking_sensors[i]);
        cars.push_back(new_car);
    }
    cout<<"OK"<<endl;
}

void open_file_csv_tv(vector<string> &name,vector<int> &screen_size, vector<string> &screen_type, vector<string> &resolution, vector<int> &three_d, vector<int> &hdr,string address)
{
	string str;
	ifstream fin;
	fin.open(address);
    
    getline(fin, str, '\n');
	while (getline(fin, str, ','))
	{	 
        name.push_back(str);
		getline(fin, str, ',');
	    screen_size.push_back(stoi(str));
		getline(fin, str, ',');
		screen_type.push_back(str);
        getline(fin, str, ',');
        resolution.push_back(str);
        getline(fin, str, ',');
        three_d.push_back(stoi(str));
        getline(fin, str, '\n');
        hdr.push_back(stoi(str));
	}
}

void market::add_tvs(vector<string> name,vector<int>screen_size, vector<string> screen_type, vector<string> resolution, vector<int>three_d, vector<int> hdr)
{
    for(int i=0;i<name.size();i++)
    {
        tv* new_tv = new tv(mobiles.size()+cars.size()+i+1,name[i],screen_size[i], screen_type[i],resolution[i],three_d[i], hdr[i]);
        tvs.push_back(new_tv);
    }
    cout<<"OK"<<endl;
}

void open_file_csv_mobile(vector<string> &name,vector<int> &weight, vector<int> &CPU_frequency, vector<int> &built_in_memory, vector<int> &RAM, vector<int> &display_size,vector<int> &camera_resolution,vector<string> &operating_system,string address)
{
	string str;
	ifstream fin;
	fin.open(address);
    
    getline(fin, str, '\n');
	while (getline(fin, str, ','))
	{	 
        name.push_back(str);
		getline(fin, str, ',');
	    weight.push_back(stoi(str));
		getline(fin, str, ',');
		CPU_frequency.push_back(stoi(str));
        getline(fin, str, ',');
        built_in_memory.push_back(stoi(str));
        getline(fin, str, ',');
        RAM.push_back(stoi(str));
        getline(fin, str, ',');
        display_size.push_back(stoi(str));
        getline(fin, str, ',');
        camera_resolution.push_back(stoi(str));
        getline(fin, str, '\n');
        operating_system.push_back(str);
    }
}

void market::add_mobiles(vector<string> name,vector<int> weight, vector<int>CPU_frequency, vector<int>built_in_memory, vector<int>RAM, vector<int>display_size,vector<int> &camera_resolution,vector<string>operating_system)
{
    for(int i=0;i<name.size();i++)
    {
        mobile* new_mobile = new mobile(i+1,name[i],weight[i],CPU_frequency[i],built_in_memory[i],RAM[i],display_size[i],camera_resolution[i],operating_system[i]);
        mobiles.push_back(new_mobile);
    }
    cout<<"OK"<<endl;
}
void market::importProducts()
{
    if(info.find("type")->second == "car" )
    {
        vector<string>name;
        vector<int>weight;
        vector<int>num_of_seats;
        vector<int>num_of_cylinders;
        vector<int>engine_capacity;
        vector<int>reverse_parking_sensors; 
        open_file_csv_car(name,weight, num_of_seats,num_of_cylinders,engine_capacity,reverse_parking_sensors,info.find("filePath")->second);
        add_cars(name,weight, num_of_seats,num_of_cylinders,engine_capacity,reverse_parking_sensors);
    }

      if(info.find("type")->second == "tv" )
    {
        vector<string>name;
        vector<int>screen_size;
        vector<string>screen_type;
        vector<string>resolution;
        vector<int>three_d;
        vector<int>hdr; 
        open_file_csv_tv(name,screen_size, screen_type,resolution,three_d,hdr,info.find("filePath")->second);
        add_tvs(name,screen_size,screen_type,resolution,three_d,hdr);

    }

    if(info.find("type")->second == "mobile" )
    {
        vector<string>name;
        vector<int>weight;
        vector<int>CPU_frequency;
        vector<int>built_in_memory;
        vector<int>RAM;
        vector<int>display_size; 
        vector<int>camera_resolution; 
        vector<string>operating_system; 
        open_file_csv_mobile(name,weight, CPU_frequency,built_in_memory,RAM,display_size,camera_resolution,operating_system,info.find("filePath")->second);
        add_mobiles(name,weight,CPU_frequency,built_in_memory,RAM,display_size,camera_resolution,operating_system);

    }

}
user* market::online_user()
{
    for(int i = 0; i < HandleInput->return_v_users().size(); i++){
        if(HandleInput->return_v_users()[i]->isOnline()){
            return HandleInput->return_v_users()[i];
        }
    }
    return nullptr;
}

void market::post_logout()
{
   
    if(HandleInput->is_admin()==true)
    {
        HandleInput->logout_admin();
        cout<<"OK"<<endl;
        return;
    }
    user *online = online_user();

    if(online == nullptr){
        cout << "Bad Request" << endl;
        return;
    }
    online->makeOffline();
    cout<<"OK"<<endl;
}

void market::signup_command()
{
    if (line.size()==10 || line.size()==12)
        signup();
    else
        cout<<"Bad Request"<<endl;
}

// void market::get_offers_command()
// { 
//     if(line.size()==8)
//         get_offers();
//     else 
//         cout<<"Bad Request"<<endl;  
// }

// void market::get_offers(){
//     user *online = online_user();
//     if(online == nullptr)
//     {   cout << "Bad Request" << endl;
//         return;
//     }
//     if (online->return_type()!="admin")
//     {
//         cout<<"Bad Request"<<endl;
//         return;
//     }
//     if(info.count("order")!=1||info.count("field")!=1 )
//     {
//         cout<<"Bad Request"<<endl;
//         return;
//     }
//         if(info.find("order")->second=="DESCEND")
//             show_offer_descend(info.find("order")->second,info.find("field")->second);
//         else if(info.find("order")->second=="ASCEND")
//             show_offer_ascend(info.find("order")->second,info.find("field")->second); 
// }
void market::offer_command()
{
    user* online = online_user();
    if(online == nullptr || HandleInput->is_admin()==true){
        cout << "Bad Request" << endl;
        return;
    }

    if (online->return_type()!="seller")
    {
        cout<<"Bad Request"<<endl;
        return;
    }
    if (line.size()==10)
    { 
        online->add_offer(stoi(info.find("productId")->second),stof(info.find("offerUnitPrice")->second),stoi(info.find("offerAmount")->second));
        cout<<"OK"<<endl;
    }
}

void market::change_offer_command()
{
    user* online = online_user();
    if(online == nullptr || HandleInput->is_admin()==true){
        cout << "Bad Request" << endl;
        return;
    }

    if (online->return_type()!="seller")
    {
        cout<<"Bad Request"<<endl;
        return;
    }
    if (line.size()==10)
    { 
        online->change_offer(stoi(info.find("productId")->second),stof(info.find("offerUnitPrice")->second),stoi(info.find("offerAmount")->second));
        cout<<"OK"<<endl;
    }
}

void market::myoffer_command()
{
    user* online = online_user();
    if(online == nullptr || HandleInput->is_admin()==true){
        cout << "Bad Request" << endl;
        return;
    }

    if (online->return_type()!="seller")
    {
        cout<<"Bad Request"<<endl;
        return;
    }
    if (line.size()==3)
    { 
        online->print_offers();
    }
 
}

void market::get_products_command()
{
    user* online = online_user();
    if(online == nullptr || HandleInput->is_admin()==true){
        cout << "Bad Request" << endl;
        return;
    }

    if (online->return_type()=="seller" || online->return_type()=="buyer"  )
   {
        if (line.size()==3)
        { 
            //print_product();
        }
   }
}

void market::product_detail_command()
{
    user* online = online_user();
    if(online == nullptr || HandleInput->is_admin()==true){
        cout << "Bad Request" << endl;
        return;
    }

    if (online->return_type()=="seller" || online->return_type()=="buyer")
   {
        if (line.size()==6)  
            print_product_detail();
   }
}

void market::get_compare_command()
{
    user* online = online_user();
    if(online == nullptr || HandleInput->is_admin()==true){
        cout << "Bad Request" << endl;
        return;
    }

    if (online->return_type()=="buyer")
   {
        if (line.size()==8)  
            get_compare();
   }
}

vector<offer*> sort_offers_by_id(vector<offer*> offers)
{
    vector<int> nums;
    vector<offer*> new_offers;
    if(offers.size()>2)
    {
        for(int i=0;i<offers.size();i++)
            nums.push_back(offers[i]->return_offer_id());
        for(int i=0;i<nums.size();i++)
        {
            int j=i+1;
            int keep = nums[j];
            while(j>1 && keep<=nums[j-1])
            {
                nums[j]=nums[j-1];
                j--;
            }
            nums[j] = keep;
        }
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<offers.size();j++)
            {
                if(nums[i] == offers[j]->return_offer_id())
                {
                    new_offers.push_back(offers[j]);
                }
            }
        }
        return new_offers;
    }
    if(offers.size()==2)
    {
        if( offers[0]->return_offer_id()>offers[1]->return_offer_id())
        {    new_offers.push_back(offers[1]);
             new_offers.push_back(offers[0]);
        }
        if( offers[1]->return_offer_id()>offers[0]->return_offer_id())
        {    new_offers.push_back(offers[0]);
             new_offers.push_back(offers[1]);
        }
    return new_offers;
    }
}

void market::get_offersOnProduct()
{
    vector<user*> users = HandleInput->return_v_users();
    vector<offer*> offers;
    for(int i=0;i<users.size();i++)
    {       
        for (int j=0;j<users[i]->return_offers().size();j++)
        {  
            cout<<"3"<<endl;
            if(users[i]->return_offers()[j]->return_product_id() == stoi(info.find("productId")->second))
                {
                        cout<<"4"<<endl;
                    offers.push_back(users[i]->return_offers()[j]);
                }
        }
    }
    offers = sort_offers_by_id(offers);
   for(int i=0;i<offers.size();i++)
   {
       cout<<"productId | productName | offerId | offerUnitPrice | offerAmount"<<endl;
       cout<<offers[i]->return_product_id()<<" | "<<" | "<<offers[i]->return_offer_id()<<" | "<<offers[i]->return_price()<<" | "<<offers[i]->return_product_nums()<<endl;
   }
}

void market::get_compare()
{
    for(int i=0; i<mobiles.size();i++)
    {  
        for(int j=0;j<mobiles.size();j++)
        {   if(mobiles[i]->return_product_id()==stoi(info.find("productId1")->second) && mobiles[j]->return_product_id()==stoi(info.find("productId2")->second))
            cout<<mobiles[i]->return_product_name()<<" | "<<mobiles[j]->return_product_name()<<endl<<"Weight:"<<mobiles[i]->return_mobile_weight()
            <<" | "<<mobiles[j]->return_mobile_weight()<<endl<<"CPUFrequency:"<<mobiles[i]->return_mobile_CPU_frequency()
            <<" | "<<mobiles[j]->return_mobile_CPU_frequency()<<endl<<"Built-inMemory:"<<mobiles[i]->return_mobile_built_in_memory()<<" | "<<mobiles[j]->return_mobile_built_in_memory()<<endl<<"RAM:"<<mobiles[i]->return_mobile_RAM()
            <<" | "<<mobiles[j]->return_mobile_RAM()<<endl<<"DisplaySize:"<<mobiles[i]->return_mobile_display_size()
            <<" | "<<mobiles[j]->return_mobile_display_size()<<endl<<"CameraResolution:"<<mobiles[i]->return_mobile_camera_resolution()<<" | "<<mobiles[j]->return_mobile_camera_resolution()
            <<endl<<"Operating System:"<<mobiles[i]->return_mobile_operating_system()<<" | "<<mobiles[i]->return_mobile_operating_system()<<endl;
        }
    }
    for(int i=0; i<cars.size();i++)
    {    
        for(int j=0;j<cars.size();j++)  
        {   if(cars[i]->return_product_id()==stoi(info.find("productId1")->second) && cars[i]->return_product_id()==stoi(info.find("productId2")->second))
            cout<<cars[i]->return_product_name()<<" | "<<cars[j]->return_product_name()<<endl<<"Weight:"<<cars[i]->return_car_weight()<<" | "<<cars[j]->return_car_weight()<<endl<<"NumOfSeats:"<<cars[i]->return_car_num_of_seats()<<" | "<<cars[j]->return_car_num_of_seats()<<endl<<"NumOfCylinders:"<<cars[i]->return_car_num_of_cylinders()
            <<" | "<<cars[j]->return_car_num_of_cylinders()<<endl<<"Engincapacity:"<<cars[i]->return_car_engine_capacity()<<" | "<<cars[j]->return_car_engine_capacity()<<"ReverseParkingSensorst:"<<cars[i]->return_car_reverse_parking_sensorst()<<" | "<<cars[j]->return_car_reverse_parking_sensorst()<<endl;
        }
    }
     for(int i=0; i<tvs.size();i++)
    {  
        for(int j=0;j<tvs.size();j++)
        {   if(tvs[i]->return_product_id()==stoi(info.find("productId1")->second)&& cars[i]->return_product_id()==stoi(info.find("productId2")->second))
            cout<<tvs[i]->return_product_name()<<" | "<<tvs[j]->return_product_name()<<endl<<"ScreenSize:"<<tvs[i]->return_tv_screen_size()<<" | "<<tvs[j]->return_tv_screen_size()<<endl<<"ScreenType:"<<tvs[i]->return_tv_screen_type()<<" | "<<tvs[j]->return_tv_screen_type()<<endl<<"Resolution:"<<tvs[i]->return_tv_resolution()<<" | "<<tvs[j]->return_tv_resolution()
            <<endl<<"3D:"<<tvs[i]->return_tv_three_d()<<" | "<<tvs[j]->return_tv_three_d()<<endl<<"HDR:"<<tvs[i]->return_tv_hdr()<<" | "<<tvs[j]->return_tv_hdr()<<endl;
        }
    }
}

void market::print_product_detail()
{ 
    for(int i=0; i<mobiles.size();i++)
    {      
        if(mobiles[i]->return_product_id()==stoi(info.find("productId")->second))
        cout<<mobiles[i]->return_product_name()<<endl<<"Weight:"<<mobiles[i]->return_mobile_weight()<<endl<<"CPUFrequency:"<<mobiles[i]->return_mobile_CPU_frequency()
        <<endl<<"Built-inMemory:"<<mobiles[i]->return_mobile_built_in_memory()<<endl<<"RAM:"<<mobiles[i]->return_mobile_RAM()<<endl<<"DisplaySize:"<<
        mobiles[i]->return_mobile_display_size()<<endl<<"CameraResolution:"<<mobiles[i]->return_mobile_camera_resolution()<<endl<<"Operating System:"<<mobiles[i]->return_mobile_operating_system()<<endl;
    }
    for(int i=0; i<cars.size();i++)
    {      
        if(cars[i]->return_product_id()==stoi(info.find("productId")->second))
        cout<<cars[i]->return_product_name()<<endl<<"Weight:"<<cars[i]->return_car_weight()<<endl<<"NumOfSeats:"<<cars[i]->return_car_num_of_seats()<<endl<<"NumOfCylinders:"<<cars[i]->return_car_num_of_cylinders()
        <<endl<<"Engincapacity:"<<cars[i]->return_car_engine_capacity()<<endl<<"ReverseParkingSensorst:"<<cars[i]->return_car_reverse_parking_sensorst()<<endl;
    }
     for(int i=0; i<tvs.size();i++)
    {  
        if(tvs[i]->return_product_id()==stoi(info.find("productId")->second))
        cout<<tvs[i]->return_product_name()<<endl<<"ScreenSize:"<<tvs[i]->return_tv_screen_size()<<endl<<"ScreenType:"<<tvs[i]->return_tv_screen_type()<<endl<<"Resolution:"<<tvs[i]->return_tv_resolution()
        <<endl<<"3D:"<<tvs[i]->return_tv_three_d()<<endl<<"HDR:"<<tvs[i]->return_tv_hdr()<<endl;
    }
}

void market::generate_discount_code_command()
{
    user* online = online_user();
    if(online == nullptr || HandleInput->is_admin()==true)
    {
        cout << "Bad Request" << endl;
        return;
    }

    if (online->return_type()!="seller")
    {
        cout<<"Bad Request"<<endl;
        return;
    }
    if (line.size()==9)
    { 
        online->add_discount_code_offer(stoi(info.find("offerId")->second),stof(info.find("discountPercent")->second), stoi(info.find("discountNumber")->second));
    }
}

void market::post_comments()
{        
    user *online = online_user();
    if(online == nullptr){
        cout << "Bad Request" << endl;
        return;
    }
    if(info.count("productId")!=1||info.count("comment")!=1)
    {
        cout<<"Bad Request"<<endl;
        return;
    }
    string productId = info.find("productId")->second;
    add_comment(info.find("comment")->second,stoi(productId),online->return_username());
}

void market::get_comments()
{
    user *online = online_user();
    if(online == nullptr){
        cout << "Bad Request" << endl;
        return;
    }
    if(info.count("productId")!=1)
    {
        cout<<"Bad Request"<<endl;
        return;
    }
    string productId = info.find("productId")->second;
    show_comment(info.find("comment")->second,stoi(productId),online->return_username());
}


void market::show_comment(string _comment,int productId,string name)
{

    if(productId > cars.size()+tvs.size()+mobiles.size())
    {

        cout<<"Bad Request"<<endl;
        return ;
    }
    for(int i=0;i<mobiles.size();i++)
    {
        if(mobiles[i]->return_product_id()==(productId))
        {
            mobiles[i]->show_comment_pr();
            return ;
        }
    }
    for(int i=0;i<cars.size();i++)
    {
        if(cars[i]->return_product_id()==(productId))
        {
            cars[i]->show_comment_pr();
            return ;
        }
    }
    for(int i=0;i<tvs.size();i++)
    {
       if(tvs[i]->return_product_id()==(productId))
        {
            tvs[i]->show_comment_pr();
            return ;
        }
    }

}

void market::add_comment(string _comment,int productId,string name)
{

    if(productId > cars.size()+tvs.size()+mobiles.size())
    {
        cout<<"Bad Request"<<endl;
        return ;
    }
    for(int i=0;i<mobiles.size();i++)
    {
        if(mobiles[i]->return_product_id()==(productId))
        {
            mobiles[i]->add_comment_pr(_comment,name);
            cout<<"OK"<<endl;
            return ;
        }
    }
    for(int i=0;i<cars.size();i++)
    {
        if(cars[i]->return_product_id()==(productId))
        {
            cars[i]->add_comment_pr(_comment,name);
            cout<<"OK"<<endl;
            return ;
        }
    }
    for(int i=0;i<tvs.size();i++)
    {
       if(tvs[i]->return_product_id()==(productId))
        {
            tvs[i]->add_comment_pr(_comment,name);
            cout<<"OK"<<endl;
            return ;
        }
    }
}


void market::post_comment_command()
{
    if(line.size()>3)
        post_comments();
    else 
        cout<<"Bad Request"<<endl;
}

void market::get_comment_command()
{
    if(line.size()>3)
        get_comments();
    else 
        cout<<"Bad Request"<<endl;
}
void market::get_offersOnProduct_command()
{
    user *online = online_user();
    if(online == nullptr){
        cout << "Bad Request" << endl;
        return;
    }
    if(info.count("productId")!=1)
    {
        cout<<"Bad Request"<<endl;
        return;
    }
    if(line.size()==6)
    {
        get_offersOnProduct();
    }
    else 
        cout<<"Bad Request"<<endl;
}

void market::get_wallet()
{
    user *online = online_user();
    if(online == nullptr){
        cout << "Bad Request" << endl;
        return;
    }
    if (online->return_type()!="seller")
    {
        cout<<"Bad Request"<<endl;
        return;
    }

    online->wallet_user(stof(info.find("count")->second));
}

void market::get_wallet_command()
{
   
    if(line.size()==6)
    {
        get_wallet();
    }
    else 
        cout<<"Bad Request"<<endl;
}

void market::post_amount_command()
{
      if(line.size()==6)
        post_amount();
    else 
        cout<<"Bad Request"<<endl; 
}

void market::post_amount()
{
 user *online = online_user();
    if(online == nullptr)
    {   cout << "Bad Request" << endl;
        return;
    }
    online->change_amount(stof(info.find("amount")->second));
}

void market::post_addtocart_command()
{

   if(line.size()==8 || line.size()==10)
        post_addtocart();
    else 
        cout<<"Bad Request"<<endl; 

}

offer*  market::find_offer_by_offerid(int offerid)
{
    vector<user*> users = HandleInput->return_v_users();
    for(int i=0;i<users.size();i++)
    {
        for(int j = 0;j<users[i]->return_offers().size();j++)
        {
            if(users[i]->return_offers()[j]->return_offer_id() == offerid)
            {
                return users[i]->return_offers()[j];
            }
        }
    }
}

user* market::find_user_by_offerid(int offerid)
{
    vector<user*> users = HandleInput->return_v_users();
    for(int i=0;i<users.size();i++)
    {
        for(int j = 0;j<users[i]->return_offers().size();j++)
        {
            if(users[i]->return_offers()[j]->return_offer_id() == offerid)
            {
                return users[i];
            }
        }
    }
}

product* market::find_product_by_productid(int productid)
{
   for(int i=0;i<mobiles.size();i++)
        {   
            if(mobiles[i]->return_product_id()==productid) 
            return mobiles[i];
        }
    for(int i=0;i<cars.size();i++)
        {   
            if(cars[i]->return_product_id()==productid)
            return cars[i];
        }
    for(int i=0;i<tvs.size();i++)
        {   
            if(tvs[i]->return_product_id()==productid)
            return tvs[i];
        }
}

void market::post_addtocart()
{
    user *online = online_user();
    if(online == nullptr)
    {   cout << "Bad Request" << endl;
        return;
    }
    if (online->return_type()!="seller")
    {
        cout<<"Bad Request"<<endl;
        return;
    }
    if(info.count("offerId")!=1||info.count("amount")!=1 )
    {
        cout<<"Bad Request"<<endl;
        return;
    }
    offer* temp_offer = find_offer_by_offerid(stoi(info.find("offerId")->second));
    user* offer_user = find_user_by_offerid(stoi(info.find("offerId")->second));
    product* temp_product = find_product_by_productid(temp_offer->return_product_id());
    if(info.count("discountçode") == 1)
    {
        online->add_to_cart(stoi(info.find("offerId")->second),stoi(info.find("amount")->second),temp_offer->return_product_id(),offer_user->return_user_id(),temp_product->return_product_name(),temp_offer->return_price(),info.find("discountçode")->second);
    }
    else if(info.count("discountçode") == 0)
        online->add_to_cart(stoi(info.find("offerId")->second),stoi(info.find("amount")->second),temp_offer->return_product_id(),offer_user->return_user_id(),temp_product->return_product_name(),temp_offer->return_price());
    else
        cout<<"Bad Request"<<endl; 

}

void market::get_cart_command()
{
      if(line.size()==3)
        get_cart();
    else 
        cout<<"Bad Request"<<endl;  
}

void market::get_cart()
{
    user *online = online_user();
    if(online == nullptr)
    {   cout << "Bad Request" << endl;
        return;
    }
    if (online->return_type()=="seller")
    {
        cout<<"Bad Request"<<endl;
        return;
    }
    online->show_carts();
}

void market::post_submitcart_command()
{
      if(line.size()==3)
        post_submitcart();
    else 
        cout<<"Bad Request"<<endl;  
}

void market::post_submitcart()
{
    user *online = online_user();
    if(online == nullptr)
    {   cout << "Bad Request" << endl;
        return;
    }
    if (online->return_type()!="seller")
    {
        cout<<"Bad Request"<<endl;
        return;
    }
    online->submitCart();
}

// void market::get_orders_command()
// {
//     if(line.size()==3)
//         get_orders();
//     else 
//         cout<<"Bad Request"<<endl;    
// }

// void market::get_orders()
// {
//  user *online = online_user();
//     if(online == nullptr)
//     {   cout << "Bad Request" << endl;
//         return;
//     }
//     if (online->return_type()!="seller")
//     {
//         cout<<"Bad Request"<<endl;
//         return;
//     }
//     online->show_orders();
// }

void market::post_commands()
{
    if(line[1]=="signup")
        signup_command();
    else if(line[1]=="login")
        login_command();
    else if(line[1]=="logout")
        post_logout_command();
    else if(line[1]=="importProducts")
        importProducts();
    else if(line[1]=="offer")
        offer_command();
    else if(line[1]=="changeOffer")
        change_offer_command();
    else if(line[1]=="generateDiscountCode")
        generate_discount_code_command();
    else if(line[1]=="comment")
        post_comment_command();
    else if(line[1]=="chargeWallet")
        post_amount_command();
    else if(line[1]=="addtoCart")
        post_addtocart_command();
    else if(line[1]=="submitCart")
        post_submitcart_command();
    else
        cout<<"Not Found"<<endl;

}

void market::get_commands()
{
    if(line[1]=="myOffers")
        myoffer_command();
    else if (line[1]=="getProducts")
        get_products_command();
    else if (line[1]=="productDetail")
        product_detail_command();
    else if (line[1]=="comments")
        get_comment_command();
    else if (line[1]=="compare")
        get_compare_command();
    else if (line[1]=="offersOnProduct")
        get_offersOnProduct_command();
    else if (line[1]=="wallet")
        get_wallet_command();
    else if (line[1]=="cart")
        get_cart_command();
    // else if (line[1]=="orders")
    //     get_orders_command();
    // else if (line[1]=="offers")
    //     get_offers_command();
    else 
    cout<<"Not Found"<<endl;
}

bool market::check_exceptions()
{
    user *online = online_user();
    if(online == nullptr){
        cout << "Permission Denied" << endl;
        return true;
    }
     return false;
}

void market::login_command(){
    if(info.find("email")->second=="admin@gmail.com" && info.find("password")->second=="admin")
    {
        HandleInput->login_admin();
        cout<<"OK"<<endl;
        return;
    }
    user *online = online_user();
    if(online != nullptr ){
        cout << "Bad Request" << endl;
        return;
    }
    if(info.count("email")!=1 || info.count("password")!=1)
    {
        cout<<"Bad Request"<<endl;
        return;
    }
    if(line.size()==8)
        HandleInput->login(info.find("email")->second,info.find("password")->second);
    else 
        cout<<"Bad Request"<<endl;
}

void market::post_logout_command()
{
    if(line.size()==3)
        post_logout();
    else 
        cout<<"Bad Request"<<endl;
}

void market::run()
{
    HandleInput->login_admin();
    while(getline(cin,str)) 
    {   
        line=removeDupWord(str);
        info=seperate_input();
        if(str.size()!=0)
        {
            if(line[0]=="POST" )
                post_commands();
            else if(line[0]=="GET")
                get_commands();
            else 
                cout<<"Bad Request"<<endl;
        }
    }
}