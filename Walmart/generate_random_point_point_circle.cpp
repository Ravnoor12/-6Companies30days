class Solution {
    double x,y,r;
public:
    Solution(double radius, double x_center, double y_center) {
        x = x_center;
        y = y_center;
        r = radius;
    }
    
    vector<double> randPoint() {
        vector<double> ans(2);
        double angle = ((double)rand() / RAND_MAX)*360;
        double rad = (double)rand() / RAND_MAX;
        rad = sqrt(rad) * r; 
       // rad = rad*rad;
        ans[0] = x + rad*cos(angle);
        ans[1] = y + rad*sin(angle);
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */