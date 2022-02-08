#include <iostream>
class Point{
    public:
        int x;
        int y;
    
        Point(int pos_x, int pos_y){
            x = pos_x;
            y = pos_y;
        };
};

class  Geometry {
    public :
        Geometry() {
            num_points = 0;
        }
        void AddPoint(const Point &point){
            point_array[num_points++] = new Point(point.x, point.y);
        }

        void PrintDistance();
        void PrintNumMeets();




    private :
        int num_points;
        Point* point_array[100];

};
int main(){
    return 0;
}