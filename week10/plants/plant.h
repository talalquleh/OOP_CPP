#pragma once
//In General -> access modifiers:
//public methods/attributes : accessible for all
//private methods/attributes : accessible  within the same class
//protected methods/attributes : accessible within the same class and the subclasses (dervied classes)



class Plant
{
    protected:
        int _ripeningTime;
        Plant(int i) : _ripeningTime(i) {}
    public:
        int getRipeningTime() const { return _ripeningTime; }
        //virtual ~Plant() {}
        virtual bool isVegetable() const { return false; }
};
//public inheritance : public ,protected members stays the same in the dervied classes
//protected inheritance : public ,protected members will be protected  in the dervied classes
//private inheritance : public ,protected members will be private  in the dervied classes
class Vegetable : public Plant
{
    public:
        bool isVegetable() const override { return true; }

    protected:
        Vegetable(int i) : Plant(i) {}
};

class Flower : public Plant
{
    protected:
        Flower(int i) : Plant(i) {}
};

class Potato : public Vegetable
{
    public:
        static Potato* instance();
		static void destroy();
    private:
        Potato() : Vegetable(5) {}
        static Potato* _instance;
};

class Pea : public Vegetable
{
    public:
        static Pea* instance();
		static void destroy();
    private:
        Pea() : Vegetable(3) {}
        static Pea* _instance;
};

class Onion : public Vegetable
{
    public:
        static Onion* instance();
		static void destroy();
    private:
        Onion() : Vegetable(4) {}
        static Onion* _instance;
};

class Rose : public Flower
{
    public:
        static Rose* instance();
		static void destroy();
    private:
        Rose() : Flower(8) {}
        static Rose* _instance;
};

class Carnation : public Flower
{
    public:
        static Carnation* instance();
		static void destroy();
    private:
        Carnation() : Flower(10) {}
        static Carnation* _instance;
};

class Tulip : public Flower
{
    public:
        static Tulip* instance();
		static void destroy();
    private:
        Tulip() : Flower(7) {}
        static Tulip* _instance;
};
/*
NOTE:
Child class always calls the constructor of the parent class,if we do not specify how, then the empty constructor of the parent is called.
,and if the parent class does not have empty constructor, it causes a compile error. 
it's  a good idea  to get used to constructor calls of attributes as in case of inheritance we cannot always avoid them.
*/
