#include <iostream> 
#include <vector> 
#include <string>
#include <queue>
using namespace std;

// 抽象苹果
class AbstractApple{
public:
    virtual void ShowName() = 0;
};
class ChinaApple : public AbstractApple{    // 中国苹果
public:
    virtual void ShowName(){
        cout << "ChinaApple!" << endl;
    };
};
class USAApple : public AbstractApple{  // 美国苹果
public:
    virtual void ShowName(){
        cout << "USAApple!" << endl;
    };
};
class JapanApple : public AbstractApple{    // 日本苹果
public:
    virtual void ShowName(){
        cout << "JapanApple!" << endl;
    };
};

// 抽象香蕉
class AbstractBanana{
public:
    virtual void ShowName() = 0;
};
class ChinaBanana : public AbstractBanana{    // 中国香蕉
public:
    virtual void ShowName(){
        cout << "ChinaBanana!" << endl;
    };
};
class USABanana : public AbstractBanana{  // 美国香蕉
public:
    virtual void ShowName(){
        cout << "USABanana!" << endl;
    };
};
class JapanBanana : public AbstractBanana{    // 日本香蕉
public:
    virtual void ShowName(){
        cout << "JapanBanana!" << endl;
    };
};


// 抽象鸭梨
class AbstractPear{
public:
    virtual void ShowName() = 0;
};
class ChinaPear : public AbstractPear{    // 中国鸭梨
public:
    virtual void ShowName(){
        cout << "ChinaPear!" << endl;
    };
};
class USAPear : public AbstractPear{  // 美国鸭梨
public:
    virtual void ShowName(){
        cout << "USAPear!" << endl;
    };
};
class JapanPear : public AbstractPear{    // 日本鸭梨
public:
    virtual void ShowName(){
        cout << "JapanPear!" << endl;
    };
};

// 抽象工厂 针对产品族
class AbstractFactory{
public:
    virtual AbstractApple* CreateApple() = 0;
    virtual AbstractBanana* CreateBanana() = 0;
    virtual AbstractPear* CreatePear() = 0;
};
class ChinaFactory : public AbstractFactory{
public:
    virtual AbstractApple* CreateApple(){
        return new ChinaApple;
    }
    virtual AbstractBanana* CreateBanana(){
        return new ChinaBanana;
    }
    virtual AbstractPear* CreatePear(){
        return new ChinaPear;
    }
};

class USAFactory : public AbstractFactory{
public:
    virtual AbstractApple* CreateApple(){
        return new USAApple;
    }
    virtual AbstractBanana* CreateBanana(){
        return new USABanana;
    }
    virtual AbstractPear* CreatePear(){
        return new USAPear;
    }
};

class JapanFactory : public AbstractFactory{
public:
    virtual AbstractApple* CreateApple(){
        return new JapanApple;
    }
    virtual AbstractBanana* CreateBanana(){
        return new JapanBanana;
    }
    virtual AbstractPear* CreatePear(){
        return new JapanPear;
    }
};


// 使用工厂模式
void test01(){
    AbstractFactory* facotry = NULL;
    AbstractApple* apple = NULL;
    AbstractBanana* banana = NULL;
    AbstractPear* pear = NULL;

    facotry = new ChinaFactory;
    apple = facotry->CreateApple();
    banana = facotry->CreateBanana();
    pear = facotry->CreatePear();

    apple->ShowName();
    banana->ShowName();
    pear->ShowName();

    delete pear;
    delete banana;
    delete apple;
    delete facotry;
}

void test02(){
    AbstractFactory* facotry = NULL;
    AbstractApple* apple = NULL;
    AbstractBanana* banana = NULL;
    AbstractPear* pear = NULL;

    facotry = new USAFactory;
    apple = facotry->CreateApple();
    banana = facotry->CreateBanana();
    pear = facotry->CreatePear();

    apple->ShowName();
    banana->ShowName();
    pear->ShowName();

    delete pear;
    delete banana;
    delete apple;
    delete facotry;
}

void test03(){
    AbstractFactory* facotry = NULL;
    AbstractApple* apple = NULL;
    AbstractBanana* banana = NULL;
    AbstractPear* pear = NULL;

    facotry = new JapanFactory;
    apple = facotry->CreateApple();
    banana = facotry->CreateBanana();
    pear = facotry->CreatePear();

    apple->ShowName();
    banana->ShowName();
    pear->ShowName();

    delete pear;
    delete banana;
    delete apple;
    delete facotry;
}


int main() {
    test01();
    test02();
    test03();

	return 0;
}



