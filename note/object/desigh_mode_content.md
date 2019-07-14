设计模式

#### 常用设计模式

[综合解析]: http://c.biancheng.net/view/1317.html

-[单例模式]: https://www.runoob.com/design-pattern/singleton-pattern.html

   - [ ] 懒汉式，线程不安全
   - [ ] 懒汉式，线程安全
   - [ ] 饿汉式
   - [ ] 双检锁/双重校验锁
   - [ ] 登记式/静态内部类
   - [ ] 枚举

-[装饰器模式]: http://c.biancheng.net/view/1366.html

   - [ ] 抽象构件（Component）角色：定义一个抽象接口以规范准备接收附加责任的对象。
   - [ ] 具体构件（Concrete    Component）角色：实现抽象构件，通过装饰角色为其添加一些职责。
   - [ ] 抽象装饰（Decorator）角色：继承抽象构件，并包含具体构件的实例，可以通过其子类扩展具体构件的功能。
   - [ ] 具体装饰（ConcreteDecorator）角色：实现抽象装饰的相关方法，并给具体构件对象添加附加的责任。

-[迭代器模式]: http://c.biancheng.net/view/1395.html

   - [ ] 抽象聚合（Aggregate）角色：定义存储、添加、删除聚合对象以及创建迭代器对象的接口。
   - [ ] 具体聚合（ConcreteAggregate）角色：实现抽象聚合类，返回一个具体迭代器的实例。
   - [ ] 抽象迭代器（Iterator）角色：定义访问和遍历聚合元素的接口，通常包含 hasNext()、first()、next() 等方法。
   - [ ] 具体迭代器（Concretelterator）角色：实现抽象迭代器接口中所定义的方法，完成对聚合对象的遍历，记录遍历的当前位置。

-[代理模式]: http://c.biancheng.net/view/1359.html

   - [ ] 抽象主题（Subject）类：通过接口或抽象类声明真实主题和代理对象实现的业务方法。
   - [ ] 真实主题（Real Subject）类：实现了抽象主题中的具体业务，是代理对象所代表的真实对象，是最终要引用的对象。
   - [ ] 代理（Proxy）类：提供了与真实主题相同的接口，其内部含有对真实主题的引用，它可以访问、控制或扩展真实主题的功能。

-[适配器模式]: http://c.biancheng.net/view/1361.html

   - [ ] 目标（Target）接口：当前系统业务所期待的接口，它可以是抽象类或接口。
   - [ ] 适配者（Adaptee）类：它是被访问和适配的现存组件库中的组件接口。
   - [ ] 适配器（Adapter）类：它是一个转换器，通过继承或引用适配者的对象，把适配者接口转换成目标接口，让客户按目标接口的格式访问适配者。

-[责任链模式]: http://c.biancheng.net/view/1383.html

   - [ ] 抽象处理者（Handler）角色：定义一个处理请求的接口，包含抽象处理方法和一个后继连接。
   - [ ] 具体处理者（Concrete Handler）角色：实现抽象处理者的处理方法，判断能否处理本次请求，如果可以处理请求则处理，否则将该请求转给它的后继者。
   - [ ] 客户类（Client）角色：创建处理链，并向链头的具体处理者对象提交请求，它不关心处理细节和请求的传递过程

-[模板模式]: http://c.biancheng.net/view/1376.html

   - [ ] 抽象类（Abstract Class）：负责给出一个算法的轮廓和骨架。它由一个模板方法和若干个基本方法构成。这些方法的定义如下。
   - [ ] 模板方法：定义了算法的骨架，按某种顺序调用其包含的基本方法。
   - [ ] 具体子类（Concrete Class）：实现抽象类中所定义的抽象方法和钩子方法，它们是一个顶级逻辑的一个组成步骤。

8. [观察者模式]: http://c.biancheng.net/view/1390.html

   - [ ] 抽象主题（Subject）角色：也叫抽象目标类，它提供了一个用于保存观察者对象的聚集类和增加、删除观察者对象的方法，以及通知所有观察者的抽象方法。
   - [ ] 具体主题（Concrete    Subject）角色：也叫具体目标类，它实现抽象目标中的通知方法，当具体主题的内部状态发生改变时，通知所有注册过的观察者对象。
   - [ ] 抽象观察者（Observer）角色：它是一个抽象类或接口，它包含了一个更新自己的抽象方法，当接到具体主题的更改通知时被调用。
   - [ ] 具体观察者（Concrete Observer）角色：实现抽象观察者中定义的抽象方法，以便在得到目标的更改通知时更新自身的状态。

-[监听器模式]: http://www.cnblogs.com/jenkov/p/listener_in_java.html

   - [ ] 事件源
   - [ ] 事件对象
   - [ ] 事件监听器

   - [ ] [Java-监听模式]: http://www.cnblogs.com/jenkov/p/listener_in_java.html

   - [ ] [Servlet]: https://www.cnblogs.com/xdp-gacl/p/3961929.html

-[外观模式]: http://c.biancheng.net/view/1369.html

    - [ ] 外观（Facade）角色：为多个子系统对外提供一个共同的接口。
    - [ ] 子系统（Sub System）角色：实现系统的部分功能，客户可以通过外观角色访问它。
    - [ ] 客户（Client）角色：通过一个外观角色访问各个子系统的功能。

-[反应器模式]: https://www.cnblogs.com/doit8791/p/7461479.html

    - [ ] 事件驱动，selector
    - [ ] 线程池处理业务
    - [ ] 拆分Reactor
-[简单工厂模式]: https://www.cnblogs.com/zhi-hao/p/4028169.html

-[工厂方法模式]: http://c.biancheng.net/view/1348.html

    - [ ] 抽象工厂（Abstract Factory）：提供了创建产品的接口，调用者通过它访问具体工厂的工厂方法 newProduct() 来创建产品。
    - [ ] 具体工厂（ConcreteFactory）：主要是实现抽象工厂中的抽象方法，完成具体产品的创建。
    - [ ] 抽象产品（Product）：定义了产品的规范，描述了产品的主要特性和功能。
    - [ ] 具体产品（ConcreteProduct）：实现了抽象产品角色所定义的接口，由具体工厂来创建，它同具体工厂之间一一对应。

-[抽象工厂模式]: http://c.biancheng.net/view/1351.html

    - [ ] 抽象工厂（Abstract Factory）：提供了创建产品的接口，它包含多个创建产品的方法 newProduct()，可以创建多个不同等级的产品。

    - [ ] 具体工厂（Concrete Factory）：主要是实现抽象工厂中的多个抽象方法，完成具体产品的创建。

    - [ ] 抽象产品（Product）：定义了产品的规范，描述了产品的主要特性和功能，抽象工厂模式有多个抽象产品。

    - [ ] 具体产品（ConcreteProduct）：实现了抽象产品角色所定义的接口，由具体工厂来创建，它 同具体工厂之间是多对一的关系。

      

####    拓展

-[观察者&监听器]: https://www.cnblogs.com/jackson-zhangjiang/p/7784694.html

-[动态代理&静态代理]: https://www.cnblogs.com/cenyu/p/6289209.html
-[Java观察器模式(observable]: https://www.cnblogs.com/cxxjohnson/p/6254967.htm

-[Java责任链模式]: https://www.cnblogs.com/ysw-go/p/5432921.html

   

