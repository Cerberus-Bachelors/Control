// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cerberus_msgs:msg/CerberusObservationTensor.idl
// generated code does not contain a copyright notice

#ifndef CERBERUS_MSGS__MSG__DETAIL__CERBERUS_OBSERVATION_TENSOR__TRAITS_HPP_
#define CERBERUS_MSGS__MSG__DETAIL__CERBERUS_OBSERVATION_TENSOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cerberus_msgs/msg/detail/cerberus_observation_tensor__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'base_ang_vel'
// Member 'proj_grav'
// Member 'command'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace cerberus_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CerberusObservationTensor & msg,
  std::ostream & out)
{
  out << "{";
  // member: base_ang_vel
  {
    out << "base_ang_vel: ";
    to_flow_style_yaml(msg.base_ang_vel, out);
    out << ", ";
  }

  // member: proj_grav
  {
    out << "proj_grav: ";
    to_flow_style_yaml(msg.proj_grav, out);
    out << ", ";
  }

  // member: command
  {
    out << "command: ";
    to_flow_style_yaml(msg.command, out);
    out << ", ";
  }

  // member: joint_pos
  {
    if (msg.joint_pos.size() == 0) {
      out << "joint_pos: []";
    } else {
      out << "joint_pos: [";
      size_t pending_items = msg.joint_pos.size();
      for (auto item : msg.joint_pos) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: joint_vel
  {
    if (msg.joint_vel.size() == 0) {
      out << "joint_vel: []";
    } else {
      out << "joint_vel: [";
      size_t pending_items = msg.joint_vel.size();
      for (auto item : msg.joint_vel) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: actions
  {
    if (msg.actions.size() == 0) {
      out << "actions: []";
    } else {
      out << "actions: [";
      size_t pending_items = msg.actions.size();
      for (auto item : msg.actions) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CerberusObservationTensor & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: base_ang_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "base_ang_vel:\n";
    to_block_style_yaml(msg.base_ang_vel, out, indentation + 2);
  }

  // member: proj_grav
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "proj_grav:\n";
    to_block_style_yaml(msg.proj_grav, out, indentation + 2);
  }

  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command:\n";
    to_block_style_yaml(msg.command, out, indentation + 2);
  }

  // member: joint_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_pos.size() == 0) {
      out << "joint_pos: []\n";
    } else {
      out << "joint_pos:\n";
      for (auto item : msg.joint_pos) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: joint_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_vel.size() == 0) {
      out << "joint_vel: []\n";
    } else {
      out << "joint_vel:\n";
      for (auto item : msg.joint_vel) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: actions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.actions.size() == 0) {
      out << "actions: []\n";
    } else {
      out << "actions:\n";
      for (auto item : msg.actions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CerberusObservationTensor & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace cerberus_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cerberus_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cerberus_msgs::msg::CerberusObservationTensor & msg,
  std::ostream & out, size_t indentation = 0)
{
  cerberus_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cerberus_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cerberus_msgs::msg::CerberusObservationTensor & msg)
{
  return cerberus_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cerberus_msgs::msg::CerberusObservationTensor>()
{
  return "cerberus_msgs::msg::CerberusObservationTensor";
}

template<>
inline const char * name<cerberus_msgs::msg::CerberusObservationTensor>()
{
  return "cerberus_msgs/msg/CerberusObservationTensor";
}

template<>
struct has_fixed_size<cerberus_msgs::msg::CerberusObservationTensor>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct has_bounded_size<cerberus_msgs::msg::CerberusObservationTensor>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct is_message<cerberus_msgs::msg::CerberusObservationTensor>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CERBERUS_MSGS__MSG__DETAIL__CERBERUS_OBSERVATION_TENSOR__TRAITS_HPP_
