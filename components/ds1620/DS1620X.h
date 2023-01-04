#include "esphome.h"
#include "DS1620.h"

class DS1620X : public PollingComponent, public Sensor {
 public:
  DS1620 temp(D5,D1,D2);
  // constructor
  DS1620X() : PollingComponent(15000) {}
  
  float get_setup_priority() const override { return esphome::setup_priority::HARDWARE; }


  void setup() override {
    // This will be called by App.setup()
	temp.config();
  }
  void update() override {
    float temperature = temp.temp_c();
    temperature_sensor->publish_state(temperature);
  }
};