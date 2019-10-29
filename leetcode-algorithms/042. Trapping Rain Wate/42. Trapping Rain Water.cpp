class Solution {
public:
    int trap(vector<int>& height) {
        int index = 0; // highest one;
        int left = 0;
        int right = 0;
        int area = 0;
        for(int i=0; i<height.size(); i++){
            if(height[i] > height[index]) index = i;
        }
        for(int i=0; i<index; i++){
            if(height[i] < left) area = area + left - height[i];   //area + capcity(blue) - pillar(black)
            else left = height[i];
        }

        for(int i=height.size()-1; i>index; i--){
            if(height[i] < right) area = area + right - height[i];
            else right = height[i];
        }
        return area;
    }
};






class Solution {
public:
    int trap(vector<int>& height) {
        int index = 0; // highest one;
        int left = 0;
        int right = 0;
        int area = 0;
        for(int i=0; i<height.size(); i++){
            if(height[i] > height[index]) index = i;
        }
        for(int i=0; i<index; i++){
            if(height[i] < left) area = area + left - height[i];
            else left = height[i];
        }

        for(int i=height.size()-1; i>index; i--){
            if(height[i] < right) area = area + right - height[i];
            else right = height[i];
        }
        return area;
    }
};
