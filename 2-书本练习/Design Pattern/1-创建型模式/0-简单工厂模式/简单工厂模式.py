# coding=utf-8
# Pythonʵ�ּ򵥹���ģʽ�ж��ַ���������һ����ʹ��һ���ֵ����洢���ڴ���������࣬
# Ȼ����ݲ����Ĳ�ͬ���ز�ͬ���ʵ��??��
# ���磬������봴��һ������Ĺ��������Զ���һ������Person�ͼ���������Student��Teacher��
# Ȼ��ʹ��һ��װ����������ע����Щ�ൽһ���ֵ��С����������ͨ���������create_person������������ͬ���͵��������?���������£�

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


# Դ: ���Ӧ�ĶԻ��� 2023/4/19
# (1) python ʵ�ֹ���ģʽ - ֪��. https://zhuanlan.zhihu.com/p/348649403.
# (2) ���ģʽpython�棨3��-��������ģʽ - CSDN����. https://blog.csdn.net/redrose2100/article/details/118440601.
# (3) python���ģʽ֮����ģʽ(Factory Pattern) - CSDN����. https://blog.csdn.net/shanglianlm/article/details/115161290.