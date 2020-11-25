class Solution {
public:
    int calculate(string s) {
        stringstream ss(s);
        int no2, no3, no1=0;
        char sign2, sign1 ='+';
        ss>>no2;
        while(ss>>sign2 && ss>>no3){
            if(sign2=='*' || sign2=='/'){
                no2 = sign2=='*' ? no2*no3 : no2/no3;
            } else {
                no1 = sign1=='+' ? no1+no2 : no1-no2;
                sign1 = sign2;
                no2 = no3;
            }
        }
        return sign1=='+' ? no1+no2 : no1-no2;
    }
};
