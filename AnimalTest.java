class Animal {
    String name;
    int age;

    Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }

    void makeSound() {
        System.out.println("Animal makes a sound.");
    }

    void move() {
        System.out.println("Animal moves.");
    }
}

class Dog extends Animal {
    Dog(String name, int age) {
        super(name, age);
    }

    @Override
    void makeSound() {
        System.out.println("Dog barks.");
    }

    @Override
    void move() {
        System.out.println("Dog runs.");
    }
}

class Cat extends Animal {
    Cat(String name, int age) {
        super(name, age);
    }

    @Override
    void makeSound() {
        System.out.println("Cat meows.");
    }

    @Override
    void move() {
        System.out.println("Cat jumps.");
    }
}

class Bird extends Animal {
    Bird(String name, int age) {
        super(name, age);
    }

    @Override
    void makeSound() {
        System.out.println("Bird chirps.");
    }

    @Override
    void move() {
        System.out.println("Bird flies.");
    }
}

public class AnimalTest {
    public static void main(String[] args) {
        Dog dog = new Dog("Buddy", 3);
        Cat cat = new Cat("Whiskers", 2);
        Bird bird = new Bird("Tweety", 1);

        dog.makeSound();
        dog.move();

        cat.makeSound();
        cat.move();

        bird.makeSound();
        bird.move();
    }
}
