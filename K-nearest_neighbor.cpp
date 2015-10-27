#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

//menyimpan parameter data training
typedef struct training{
    double outlook;
    double temperature;
    double humidity;
    double wind;
    double play;
    double distance;
}dataset;

//menghitung euclidian distance
double euclidianDistance(dataset dt[], dataset sd, int n){
    for(int i=0;i<n;i++){
        double a = dt[i].outlook-sd.outlook;    //menghitung selisih outlook
        double b = dt[i].temperature-sd.temperature;    //menghitung selisih temperature
        double c = dt[i].humidity-sd.humidity;      //menghitung selisih humidity
        double d = dt[i].wind-sd.wind;      ////menghitung selisih wind
        dt[i].distance = sqrt(pow(a,2)+pow(b,2)+pow(c,2)+pow(d,2));     //menghitung distance dengan rumus euclidian distance
    }
}

//melakukan sorting secara ascending
double insertion_sort(dataset dt[], int length){
    for (int i = 1; i < length; i++){
        for (int j = i; j >= 1; j--){
            if (dt[j].distance < dt[j-1].distance)
            {
                double temp = dt[j].distance;
                dt[j].distance = dt[j-1].distance;
                dt[j-1].distance = temp;
            }
            else
                break;
        }
    }
}

//melakukan voring sebagai dasar prediksi data
int vote(dataset dt[], int k){
    int yes, no;
    for(int i=0;i<k;i++){
        if(dt[i].play==1)
            yes++;      //menghitung voting yes
        else
            no++;       //menghitung voting no
    }
    //voting data dominan
    if(yes>no)  cout << "Play Tenis : Yes";
    else cout << "Play Tenis : No";
}

int main(){
    dataset dd[100];    //menyimpan data training
    dataset ss;         //menyimpan data yang akan dipresiksi
    int tc;             //menyimpan jumlah data training
    int knn;            //menyimpan nilai k neighbor yang akan diambil untuk voting
    cout << "Masukan jumlah data training" <<endl;
    cin >> tc ;
    cout << "Masukan data training" <<endl;
    for(int i=0;i<tc;i++){
        cin >> dd[i].outlook >> dd[i].temperature >> dd[i].humidity >> dd[i].wind >> dd[i].play;
    }
    cout << "Masukan data yang ingin diprediksi" <<endl;
    cin >> ss.outlook >> ss.temperature >> ss.humidity >> ss.wind;
    cout << "Masukan nilai K"<<endl;
    cin >> knn;
    euclidianDistance(dd, ss, tc);
    insertion_sort(dd, tc);
    vote(dd, knn);
    return 0;
}
