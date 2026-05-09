#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

// Observer Interface
class Observer {
	public:
		virtual ~Observer() = default;
		virtual void update(const std::string& news) = 0;
};

// Publisher
class NewsPublisher {
	private:
		std::vector<Observer*> subscribers;
	public:
		void subscribe(Observer* observer) {
			subscribers.push_back(observer);
		}
		void unsubscribe(Observer* observer) {
			subscribers.erase( std::remove(subscribers.begin(),subscribers.end(), observer),subscribers.end());
		}

		void notify(const std::string& news) {
			for(Observer* obs : subscribers) {
				obs->update(news);
			}
		}
};

// Concrete Observers
class PhoneUser : public Observer {
	public:
		void update(const std::string& news) override {
			std::cout<<"[Phone User] New Alert" << news <<std::endl;
		}
};

class EmailUser : public Observer {
	public:
		void update(const std::string& news) override {
			std::cout<<"[Email User] Received in Inbox: "<<news<<std::endl;
		}
};

class TVUser : public Observer {
	public:
		void update(const std::string& news) override {
			std::cout<<"[TV User] Breaking News on TV:" <<news<<std::endl;
		}
};

// Main
int main() {
	NewsPublisher publisher;
	PhoneUser phone;
	EmailUser email;
	TVUser tv;

	// Subscribe
	publisher.subscribe(&phone);
	publisher.subscribe(&email);
	publisher.subscribe(&tv);

	std::cout<<"-----Breaking News-----"<<std::endl;
	publisher.notify("Election results announced:\n");
	std::cout<<"-----Another News (TV Unsubscribed)----\n";
	publisher.unsubscribe(&tv);
	publisher.notify("Stock Market Crashes!");
	return 0;
}

