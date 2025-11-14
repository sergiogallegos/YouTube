print("Hello, World!")


class MyClass:
    def __init__(self, name):
        self.name = name

    def say_hello(self):
        print(f"Hello, {self.name}!")


def say_hello():
    print("Hello, World!")


def main():
    print("This is the main function.")
    print("Executing main function...")
    say_hello()
    my_class = MyClass("John")
    my_class.say_hello()


if __name__ == "__main__":
    main()
