class Subject:
    def request(self):
        pass

class RealSubject(Subject):
    def request(self):
        print("RealSubject request")

class Proxy(Subject):
    def __init__(self, real_subject: RealSubject):
        self.real_subject = real_subject

    def request(self):
        self.before_request()
        self.real_subject.request()
        self.after_request()

    def before_request(self):
        print("Proxy before request")

    def after_request(self):
        print("Proxy after request")

# 可以用在访问代理的时候，前后都要做一个操作
if __name__ == '__main__':
    real_subject = RealSubject()
    proxy = Proxy(real_subject)

    proxy.request()
