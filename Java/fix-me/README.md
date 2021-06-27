# fix-me

Here we simulate broker-market communication via simplified [fix-message](https://ru.wikipedia.org/wiki/Financial_Information_eXchange).
There are three components. Broker - it sends requests (buy or sell) to market.
Market - processes requests from broker, answer with 'ok/error'.
Router - handles communication between broker and market, it is a server. 

## Features

* Rich terminal UI
* Market stores transactions in a MySQL database
* If router is down, broker and market wait for reconnection
* If broker or market are down, router waits for them to reconnect and tries to send queued messages

## Installation

You need to have Java and Maven on your machine.
Then you simply `mvn clean package` in project root.

## Running

You need to start three terminal windows.
In each one you start an individual component.

`java -jar Router/target/Router.jar` <br>
`java -jar Market/target/Market.jar` <br>
`java -jar Broker/target/Broker.jar`

*In each component you can type `help` to see available commands.
'$' denotes program answers and messages, user input has no prefix.*

## Example

```
java -jar Router/target/Router.jar
$ Registered broker
$ Registered market
exit
```

```
java -jar Market/target/Market.jar
$ Trying to connect to server...
$ Connected to server!
$ Initialized with id 0
instruments set tomato 100 1
exit
```

```
java -jar Broker/target/Broker.jar
$ Trying to connect to server...
$ Connected to server!
$ Initialized with id 1
instruments buy 0 tomato 10 1
$ Success
instruments all
$ tomato : quantity = 10, price = 0
instruments buy 0 potato 10 1
$ Error : INSTRUMENT-NOT-FOUND
exit
```

## Resources

* [A Guide to the Java ExecutorService](https://www.baeldung.com/java-executor-service-tutorial)
* [demo-sockets-io-nio-nio2](https://github.com/aliakh/demo-sockets-io-nio-nio2)
* [Java sockets I/O: blocking, non-blocking and asynchronous](https://liakh-aliaksandr.medium.com/java-sockets-i-o-blocking-non-blocking-and-asynchronous-fb7f066e4ede)
* [Изучаю FIX протокол с нуля. Разбор протокола, первый код на c#](https://smart-lab.ru/blog/310446.php)
* [Handling multiple I/O from one thread with NIO Selector](https://www.waitingforcode.com/java-i-o/handling-multiple-io-one-thread-nio-selector/read)
* [Java NIO](https://www.tune-it.ru/web/ivanuskov/blog/-/blogs/java-nio)
* [Java NIO Tutorial](http://tutorials.jenkov.com/java-nio/index.html)
* [Руководство по Hibernate](https://proselyte.net/tutorials/hibernate-tutorial/introduction/)