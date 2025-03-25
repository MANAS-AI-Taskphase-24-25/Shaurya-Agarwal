#include<rclcpp/rclcpp.hpp>
#include<std_msgs/msg/string.hpp>
#include<chrono>
#include<thread>

using namespace std::chrono_literals;

class ChatNode:public rclcpp::Node
{
public:
ChatNode():Node("chat_node")
{
publisher_=this->create_publisher<std_msgs::msg::String>("chat_topic",10);

subscription_=this->create_subscription<std_msgs::msg::String>("chat_topic", 10, 
[this](std_msgs::msg::String::UniquePtr msg) {
RCLCPP_INFO(this->get_logger(), "Received: '%s'", msg->data.c_str());
});
timer_=this->create_wall_timer(3s,[this](){
std_msgs::msg::String msg;
msg.data="Hello from Timothy :)";
RCLCPP_INFO(this->get_logger(),"Publishing '%s'",msg.data.c_str());
publisher_->publish(msg);
}); 
}

private:
rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
rclcpp::TimerBase::SharedPtr timer_;
};
int main(int argc, char **argv)
{
rclcpp::init(argc,argv);
rclcpp::spin(std::make_shared<ChatNode>());
rclcpp::shutdown();
return 0;
}
