class Solution {
public:
    // English numbers process in chunks of 3 digits (thousand, million, billion)
    // Required 3 lookup tables: below 20, tens and thousands scale
    // Recursive 3 digit helper function needed
    // Process right to left using %1000 and /1000, apply corresponding scale on non-zero 3 digit chunk

    string thousands[4]= {"", " Thousand", " Million", " Billion"};
    string tens[10]= {"", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    string ones[20]= {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
    
    // Helper function
    string helper(int n){
        if(n<20) return ones[n];
        if(n<100) return tens[n/10]+ helper(n%10);
        if(n<1000) return helper(n/100)+ " Hundred" + helper(n%100);
        // the thousands can be selected on powers of 1000
        for(int i=3; i>=0; i--){
            if(n>=pow(1000, i)){
                return helper(n/pow(1000, i))+thousands[i]+helper(n%(int)pow(1000, i));
            }
        }
        return "";
    }

    string numberToWords(int num) {
        if(num==0) return "Zero";
        return helper(num).substr(1);   // To remove the trailing first space (every number has space before it in our array)
    }
};