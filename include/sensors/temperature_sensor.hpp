/**
 * @file temperature_sensor.hpp
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 */
#pragma once

#include <vector>

#include "sensor.hpp"
#include "i2c/i2c_comm.hpp"


namespace eekhdv
{

/*
 * Temperature sensors class
**/
class temperature_sensor final : public sensor
{
public:
  /// @brief 
  /// @param
  temperature_sensor(uint8_t i2c_bus_) : sensors_{}, i2c_bus{i2c_bus_}
  { }

  temperature_sensor(std::vector<sensor_type>& list, uint8_t i2c_bus_) : sensors_{list}, i2c_bus{i2c_bus_}
  { }

  void measure() final override;

  void add_sensor(const sensor_type& sensor) final override;

  static constexpr inline const char* get_base_sensor_name() { return base_sensor_name; }

private:
  static constexpr const char* base_sensor_name { "TMP" };
  
  std::vector<sensor_type> sensors_;
  
  i2c_comm i2c_bus;
};

} // namespace eekhdv
