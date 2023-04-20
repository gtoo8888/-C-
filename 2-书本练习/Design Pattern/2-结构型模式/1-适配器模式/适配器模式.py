class Target:
    def request(self):
        pass

class Adaptee:
    def specific_request(self):
        print("Adaptee specific request")

class Adapter(Target):
    def __init__(self, adaptee: Adaptee):
        self.adaptee = adaptee

    def request(self):
        self.adaptee.specific_request()

if __name__ == '__main__':
    adaptee = Adaptee()
    adapter = Adapter(adaptee)

    adapter.request()
