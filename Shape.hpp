

class s_Shape{
public:
    virtual void print() = 0;
    virtual ~s_Shape() {}
};


class s_Rectangle : public s_Shape{
public:
    void print(){ std::cout << "I am a Rectangle";}
};


class s_Circle : public s_Shape{
public:
    void print(){ std::cout << "I am a Circle";}
};
