# coding=utf-8
# Python实现简单工厂模式有多种方法，其中一种是使用一个字典来存储用于创建对象的类，
# 然后根据参数的不同返回不同类的实例??。
# 例如，如果您想创建一个人类的工厂，可以定义一个基类Person和几个派生类Student，Teacher等
# 然后使用一个装饰器函数来注册这些类到一个字典中。最后，您可以通过工厂类的create_person方法来创建不同类型的人类对象?。代码如下：

from abc import ABCMeta,abstractmethod
class Person(metaclass=ABCMeta):
    @abstractmethod
    def get_name(self):
        pass
    @abstractmethod
    def set_name(self,name):
        pass

class Student(Person):
    def __init__(self):
        self.__name=""
    def get_name(self):
        return self.__name
    def set_name(self,name):
        self.__name=name

class Teacher(Person):
    def __init__(self):
        self.__name=""
    def get_name(self):
        return self.__name
    def set_name(self,name):
        self.__name=name

OP_FACTORY = {}
def register_op(cls):
    cls_name = cls.__name__
    def register(cls):
        OP_FACTORY[cls_name] = cls
        return register(cls)
    class PersonFactory(metaclass=ABCMeta):
        @abstractmethod
        def create_person(self):
            pass

class StudentFactory(PersonFactory):
    def create_person(self):
        return Student()

class TeacherFactory(PersonFactory):
    def create_person(self):
        return Teacher()

if __name__=="__main__":
    s=StudentFactory().create_person()
    t=TeacherFactory().create_person()
    s.set_name("Tom")
    t.set_name("Mr Jack")
    print(s.get_name())
    print(t.get_name())


# 源: 与必应的对话， 2023/4/19
# (1) python 实现工厂模式 - 知乎. https://zhuanlan.zhihu.com/p/348649403.
# (2) 设计模式python版（3）-工厂方法模式 - CSDN博客. https://blog.csdn.net/redrose2100/article/details/118440601.
# (3) python设计模式之工厂模式(Factory Pattern) - CSDN博客. https://blog.csdn.net/shanglianlm/article/details/115161290.