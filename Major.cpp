#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
using namespace std;

// Getting Input from User
int GetInput()
{
    int choice;
    do
    {
        cout << "Enter your choice : ";
        cin >> choice;

        if (choice < 1 || choice > 5)
        {
            cout << "Please Enter an integer between 1 and 5\n";
        }
    } while (choice < 1 || choice > 5); //Inpt Validation
    return choice;
}

// Yeh main menu saare prompts de ga 
void DisplayMainMenu()
{
    cout << "         --------Main Menu-------" << endl << endl << endl;
    cout << "Please select from the following options :\n";
    cout << "1. View Profile :" << endl;
    cout << "2. Create Profile :\n";
    cout << "3. Update Profile :\n";
    cout << "4. Delete Profile :\n";
    cout << "5. Exit :\n";
}

// Create Profile Menu
void CreateProfileMenu(string& name, string& cnic ,float& housesize, char& housesizetype, float& sizeinsqfeet, int& rooms,
    int bulb[100], int fridge[100], int fans[100], int sockets[100], int consump[10], int& energyused, int& totalappliances,
    int& noofplates, float& systemcapacity, float& costofpanels, float& billsaving, float& bill)
{
    cout << "Enter your full name : ";
    cin.ignore();
    getline(cin, name); // getline for entering full name
    cout << "Enter Your CNIC: ";
    cin >> cnic;

    string filekaname = cnic + "_"+name  + "_profile.txt"; // File name 
    ofstream solarfile(filekaname); // For storing in a file so we can read it later
    solarfile << "Name : " << name << endl;
    solarfile << "CNIC : " << cnic << endl;
    ofstream showprofile("profile_list.txt", ios::app);// append iss liye take we can easily add the names of profiles created later
    if (!showprofile)
    {
        cout << "Error in opening profile list\n";
    }
    else
    {
        showprofile << filekaname << endl;
    }

    solarfile << "Name : " << name << endl;
    if (!solarfile)
    {
        cout << "Error in opening the file " << endl;
    }

    do
    {
        cout << "Enter 'M' for marla and 'K' for Kanal : ";
        cin >> housesizetype;
        solarfile << "House Size Type : " << housesizetype << endl;
        if (housesizetype != 'M' && housesizetype != 'K')
        {
            cout << "Invalid Input. The Input is case sensitive\n";
        }
    } while (housesizetype != 'M' && housesizetype != 'K');

    if (housesizetype == 'M')
    {
        do
        {
            cout << "Enter your house size in Marla : ";
            cin >> housesize;
            if (housesize <= 0)
            {
                cout << "Enter a positive integer for house size\n";
            }
            solarfile << "House Size : " << housesize << endl;

        } while (housesize <= 0);

        sizeinsqfeet = housesize * 250;
        solarfile << "Size in sq.Feet : " << sizeinsqfeet << endl;
    }
    else if (housesizetype == 'K')
    {
        do {
            cout << "Enter your house size in Kanal : ";
            cin >> housesize;
            if (housesize <= 0)
            {
                cout << "Enter a positive integer for house size\n";
            }
            solarfile << "House Size : " << housesize << endl;
        } while (housesize <= 0);

        sizeinsqfeet = 20 * housesize * 250;
        solarfile << "Size in sq.Feet : " << sizeinsqfeet << endl;
    }

    solarfile << endl << endl;

    do
    {
        cout << "Enter number of rooms : ";
        cin >> rooms;
        if (rooms <= 0)
        {
            cout << "Invalid Input!\n";
        }
        solarfile << "Rooms : " << rooms << endl << endl;
    } while (rooms <= 0);

    for (int i = 0; i < rooms; i++)
    {
        cout << "--------Room " << i + 1 << " --------" << endl;

        do
        {
            cout << "Enter Number of Bulbs : ";
            cin >> bulb[i];
            solarfile << "Bulbs : " << bulb[i] << endl;

            if (bulb[i] < 0)
            {
                cout << "Enter a positive integer\n";
            }

        } while (bulb[i] < 0);

        do
        {
            cout << "Enter Number of Fridges : ";
            cin >> fridge[i];
            solarfile << "Fridge : " << fridge[i] << endl;

            if (fridge[i] < 0)
            {
                cout << "Enter a positive integer\n";
            }

        } while (fridge[i] < 0);

        do
        {
            cout << "Enter Number of Fans : ";
            cin >> fans[i];
            solarfile << "Fans : " << fans[i] << endl;

            if (fans[i] < 0)
            {
                cout << "Enter a positive integer\n";
            }

        } while (fans[i] < 0);

        do
        {
            cout << "Enter Number of sockets : ";
            cin >> sockets[i];
            solarfile << "Sockets : " << sockets[i] << endl << endl << endl << endl;

            if (sockets[i] < 0)
            {
                cout << "Enter a positive integer\n";
            }

        } while (sockets[i] < 0);
    }

    for (int i = 0; i < rooms; i++)
    {
        consump[0] += bulb[i];
        consump[1] += fridge[i];
        consump[2] += fans[i];
        consump[3] += sockets[i];
    }

    totalappliances = consump[0] + consump[1] + consump[2] + consump[3];
    solarfile << "Total Appliances : " << totalappliances << endl;

    energyused = totalappliances * 250;
    solarfile << "Energy Used : " << energyused << " Watts " << endl;

    noofplates = energyused / 500;
    solarfile << "No. of plates : " << noofplates << endl;

    systemcapacity = noofplates / 2;
    solarfile << "Capacity Of system : " << systemcapacity << " KW" << endl;

    costofpanels = noofplates * 30000;
    solarfile << "Cost Of Panels : " << costofpanels << " pkr" << endl;

    do
    {
        cout << "Enter your bill for the whole year : ";
        cin >> bill;
        solarfile << "Bill of year : " << bill << endl;

        if (bill < 0)
        {
            cout << "Please Enter a positive integer\n";
        }

        if (bill == 0)
        {
            cout << "Bill is too low.\n";
        }
    } while (bill < 0);

    bill /= 12;
    cout << endl;

    solarfile << "Avg. Bill per month is : " << bill << endl;

    billsaving = bill / 2;// The savings from a solar system is around 50%

    solarfile << "Saving per month : " << billsaving;
    solarfile << "The installation Cost will be around " << systemcapacity * 40000 << "Pkr as the cost per KWH is Rs. 40k" << endl;
    solarfile.close();
    showprofile.close();
}








void showProfiles()
{
    ifstream showprofiles("profile_list.txt");
    if (!showprofiles)
    {
        cout << "No available files rn" << endl;
        return;
    }

    cout << "Available Profiles:\n";
    string line;
    int i = 0;
    string profile[100];

    //Reading the .files
    while (getline(showprofiles, line))
    {
        profile[i] = line;
        cout << (i + 1) << " : " << profile[i] << endl;
        i++;
    }
    showprofiles.close();

    // Ask the user 
    int choice;
    cout << "Enter the number of the profile you want to view: ";
    cin >> choice;

    // Validation
    if (choice < 1 || choice > i)
    {
        cout << "Invalid choice. Please enter a valid number.\n";
        return;
    }

    // Get the selected profile file name
    string openProfile = profile[choice - 1];

    ifstream profileFile(openProfile);

    if (!profileFile)
    {
        cout << "Error openngfile: " << openProfile << endl;
        return;
    }

    cout << endl;
    cout << openProfile << ":\n";
    string profileLine;
    while (getline(profileFile, profileLine))
    {
        cout << profileLine << endl;
    }
    profileFile.close();
}




void deleteprofile()
{
    string name;
    string filekaname;
    string cnic;

    cout << "Enter your name as in profile created: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Your Cnic : ";
    cin >> cnic;
    filekaname = cnic +"_"+name + "_profile.txt";

    ifstream file(filekaname);

    if (!file)
    {
        cout << "No profile found\n";
        return;
    }

    file.close();

    char rep;
    do
    {
        cout << "Do you want to delete this file? 'Y' for Yes and 'N' for No: ";
        cin >> rep;
        if (rep != 'Y' && rep != 'N')
        {
            cout << "Invalid Input. Please enter 'Y' or 'N'.\n";
        }

        if (rep == 'Y')
        {
            int status = remove(filekaname.c_str());

            if (status == 0)
            {
                cout << "File Deleted Successfully\n";

                ifstream profileList("profile_list.txt");
                ofstream newlist("temp_list.txt");
                string line;

                bool profileFound = false;

                while (getline(profileList, line))
                {
                    if (line != filekaname)
                    {
                        newlist << line << endl;
                    }
                    else
                    {
                        profileFound = true;
                    }
                }

                profileList.close();
                newlist.close();

                if (profileFound)
                {
                    remove("profile_list.txt");
                    ifstream read("temp_list.txt");
                    ofstream final("profile_list.txt");

                    while (getline(read, line))
                    {
                        final << line << endl;
                    }

                    read.close();
                    final.close();
                    cout << "Profile removed from profile list.\n";
                }
                else
                {
                    cout << "Profile not found in the profile list.\n";
                }
            }
            else
            {
                cout << "Error in deleting the file\n";
            }
        }
        else if (rep == 'N')
        {
            cout << "File Not Deleted\n";
        }

    } while (rep != 'Y' && rep != 'N');
}

int getInput()
{
    int choice;
    do
    {
        cout << "Enter your choice : ";
        cin >> choice;

        if (choice < 1 || choice > 5)
        {
            cout << "Enter Between 1 and 5!\n";
        }

    } while (choice < 1 || choice > 5);
    return choice;
}

void updateProfile(string& name, string& cnic, float& housesize, char& housesizetype, float& sizeinsqfeet, int& rooms,
    int bulb[100], int fridge[100], int fans[100], int sockets[100], int consump[10], int& energyused,
    int& totalappliances, int& noofplates, float& systemcapacity, float& costofpanels, float& billsaving,
    float& bill)
{
    cout << "Enter your name as in profile created: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your cnic: ";
    cin >> cnic;

    string filekaname = cnic +"_"+ name + "_profile.txt";
    ifstream file(filekaname);

    if (!file) {
        cout << "Profile : " << name << " not found. Please go to main menu to create a profile first.\n";
        return;
    }

    file.close();

    int choice;
    bool update = true;

    while (update) {
        cout << "What would you like to update?\n";
        cout << "1. House Size\n";
        cout << "2. Appliances and Usage\n";
        cout << "3. Bill Information\n";
        cout << "4. Whole Profile\n";
        cout << "5. Exit to Main Menu\n";
        choice = getInput();

        switch (choice) {
        case 1:
            cout << "Enter 'M' for Marla or 'K' for Kanal: ";
            cin >> housesizetype;
            cout << "Enter the new house size: ";
            cin >> housesize;

            if (housesizetype == 'M') {
                sizeinsqfeet = housesize * 250;
            }
            else if (housesizetype == 'K') {
                sizeinsqfeet = 20 * housesize * 250;
            }

            cout << "Updated house size: " << sizeinsqfeet << " sq. feet.\n";
            break;

        case 2:
            cout << "Enter number of rooms: ";
            cin >> rooms;

            for (int i = 0; i < rooms; i++) {
                cout << "--------Room " << i + 1 << "--------\n";
                cout << "Enter Number of Bulbs: ";
                cin >> bulb[i];
                cout << "Enter Number of Fridges: ";
                cin >> fridge[i];
                cout << "Enter Number of Fans: ";
                cin >> fans[i];
                cout << "Enter Number of Sockets: ";
                cin >> sockets[i];
            }


            for (int i = 0; i < 10; i++) {
                consump[i] = 0;
            }

            totalappliances = 0;
            for (int i = 0; i < rooms; i++) {
                consump[0] += bulb[i];
                consump[1] += fridge[i];
                consump[2] += fans[i];
                consump[3] += sockets[i];
            }

            totalappliances = consump[0] + consump[1] + consump[2] + consump[3];
            energyused = totalappliances * 250;
            cout << "Updated total energy usage to " << energyused << " Watts.\n";
            break;

        case 3:
            cout << "Enter your yearly electricity bill: ";
            cin >> bill;
            bill /= 12;
            billsaving = bill / 2;

            cout << "Updated monthly bill to " << bill << " and savings to " << billsaving << ".\n";
            break;

        case 4:
            cout << "Enter 'M' for Marla or 'K' for Kanal: ";
            cin >> housesizetype;
            cout << "Enter the new house size: ";
            cin >> housesize;

            if (housesizetype == 'M') {
                sizeinsqfeet = housesize * 250;
            }
            else if (housesizetype == 'K') {
                sizeinsqfeet = 20 * housesize * 250;
            }

            cout << "Updated house size: " << sizeinsqfeet << " sq. feet.\n";

            cout << "Enter number of rooms: ";
            cin >> rooms;

            for (int i = 0; i < rooms; i++) {
                cout << "--------Room " << i + 1 << "--------\n";
                cout << "Enter Number of Bulbs: ";
                cin >> bulb[i];
                cout << "Enter Number of Fridges: ";
                cin >> fridge[i];
                cout << "Enter Number of Fans: ";
                cin >> fans[i];
                cout << "Enter Number of Sockets: ";
                cin >> sockets[i];
            }


            for (int i = 0; i < 10; i++) {
                consump[i] = 0;
            }

            totalappliances = 0;
            for (int i = 0; i < rooms; i++) {
                consump[0] += bulb[i];
                consump[1] += fridge[i];
                consump[2] += fans[i];
                consump[3] += sockets[i];
            }

            totalappliances = consump[0] + consump[1] + consump[2] + consump[3];
            energyused = totalappliances * 250;
            cout << "Updated total energy usage to " << energyused << " Watts.\n";

            cout << "Enter your yearly electricity bill: ";
            cin >> bill;
            bill /= 12;
            billsaving = bill / 2;

            cout << "Updated monthly bill to " << bill << " and savings to " << billsaving << ".\n";
            break;

        case 5:
            cout << "Exiting Update Menu\n";
            update = false;
            break;

        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }

        ofstream solarfile(filekaname);
        if (!solarfile) {
            cout << "Error opening file for writing updates.\n";
            return;
        }

        solarfile << "Name: " << name << "\n";
        solarfile << "House Size: " << housesize << "\n";
        solarfile << "House Size Type: " << housesizetype << "\n";
        solarfile << "Size in sq. feet: " << sizeinsqfeet << "\n";
        solarfile << "Total Appliances: " << totalappliances << "\n";
        solarfile << "Energy Used: " << energyused << " Watts\n";
        solarfile << "Bill per Month: " << bill << "\n";
        solarfile << "Savings per Month: " << billsaving << "\n";
        solarfile.close();

        cout << "Profile updated successfully.\n";
    }
}





int main()
{
    string name,cnic;
    char housesizetype;
    float sizeinsqfeet, housesize, systemcapacity, costofpanels, billsaving, bill;
    int rooms, bulb[100] = { 0 }, fridge[100] = { 0 }, fans[100] = { 0 }, sockets[100] = { 0 }, consump[10] = { 0 },
        energyused, totalappliances, noofplates;

    int choice;
    bool menu = true;

    while (menu)
    {
        DisplayMainMenu();
        choice = GetInput();

        switch (choice)
        {
        case 1:
            showProfiles();
            break;
        case 2:
            CreateProfileMenu(name,cnic, housesize, housesizetype, sizeinsqfeet, rooms, bulb, fridge, fans, sockets, consump,
                energyused, totalappliances, noofplates, systemcapacity, costofpanels, billsaving, bill);
            break;
        case 3:
            updateProfile(name,cnic, housesize, housesizetype, sizeinsqfeet, rooms, bulb, fridge, fans, sockets, consump,
                energyused, totalappliances, noofplates, systemcapacity, costofpanels, billsaving, bill);
            break;
        case 4:
            deleteprofile();
            break;
        case 5:
            cout << "\n\n\nThanks For Choosing the SMB Solar Corpration. \n           Powering Your Future, Brightly!\n\n\n\n";
            menu = false;
            break;
        default:
            cout << "Invalid Input\n";
            break;
        }
    }

    return 0;
}
