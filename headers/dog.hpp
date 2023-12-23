#include<string>
#include<string_view>

class Dog {
   private:
      std::string name{};
   public:
      Dog()=default;
      ~Dog();
      std::string getName() const
      {
         return this->name;
      }

      void setName(const std::string name) 
      {
         this->name = name;
      }
      Dog(std::string name)
      {
         this->name = name;
      }
      void printInfo();
};