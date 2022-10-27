class FoodRatings {
public:
    map<string,int> foodRate;
    map<string,string> foodCusine;
    map<string,set<pair<int,string>>> cusineRating;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0;i<n;i++){
            foodRate[foods[i]]=ratings[i];
            cusineRating[cuisines[i]].insert({-ratings[i],foods[i]});
            foodCusine[foods[i]]=cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        int currRate = foodRate[food];
        foodRate[food]=newRating;
        string cusine = foodCusine[food];
        cusineRating[cusine].erase({-currRate, food});
        cusineRating[cusine].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        return cusineRating[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */