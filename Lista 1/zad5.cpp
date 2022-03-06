#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

vector<float> read_file(string file_path)
{
    ifstream file;
    vector<float> vect;
    file.open(file_path);
    float x;

    if (!file) 
    {
        cerr << "Unable to open .txt file";
        exit(1);
    }
    while (file >> x) 
    {
        vect.push_back(x);
    }
    return vect;
}

int save_file (string file_path, vector<float> vec)
{
    ofstream c_file;
    c_file.open (file_path);
    for (int i = 0; i < vec.size(); i++)
    {
        c_file << vec[i];
        c_file << " ";
    }
    c_file.close();
    return 0;
}

vector <float> vec_multiply(vector<float> vect_a, vector<float> vect_b)
{
    vector<float> vect_c;
    int a_deg, b_deg, c_deg;
    //stopien iloczynu wielomianu jest rowny sumie stopni

    a_deg = vect_a[0];
    b_deg = vect_b[0];
    c_deg = a_deg + b_deg;

    cout << "Stopień wielomianu A(x): " << a_deg << endl;
    cout << "Stopień wielomianu B(x): " << b_deg << endl;
    cout << "Stopień wielomianu C(x) = A(x)B(x): " << c_deg << endl;

    vect_c.push_back(c_deg);

    vector<float> x;

    int i,j;

    //pomocniczo

    while (i<=c_deg)
    {
        x.push_back(0);
        i++;
    }

    //wykluczamy 0 bo to stopien wielomianu

    for(i=1;i<vect_a.size();i++)
    {
        for (j=1; j < vect_b.size(); j++)
        {
            x[i+j-2] += vect_a[i]*vect_b[j];
        }
    }

    for(i = 0; i < x.size(); i++)
    {
        vect_c.push_back(x[i]);
    }


    return vect_c;

}

int main()
{
    vector<float> vect_a,vect_b, vect_c;
    vect_a = read_file("a.txt");
    vect_b = read_file("b.txt");
    vect_c = vec_multiply(vect_a, vect_b);
    save_file("c.txt", vect_c);
    return 0;
}