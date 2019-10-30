#pragma once

using namespace perc;

#include <iostream>

#define map_str(X) {X, #X}
std::map<BULK_MESSAGE_ID, std::string> bulk_message_names = {
       map_str(DEV_GET_DEVICE_INFO),
       map_str(DEV_GET_TIME),
       map_str(DEV_GET_AND_CLEAR_EVENT_LOG),
       map_str(DEV_GET_SUPPORTED_RAW_STREAMS),
       map_str(DEV_RAW_STREAMS_CONTROL),
       map_str(DEV_GET_CAMERA_INTRINSICS),
       map_str(DEV_GET_MOTION_INTRINSICS),
       map_str(DEV_GET_EXTRINSICS),
       map_str(DEV_SET_CAMERA_INTRINSICS),
       map_str(DEV_SET_MOTION_INTRINSICS),
       map_str(DEV_SET_EXTRINSICS),
       map_str(DEV_LOG_CONTROL),
       map_str(DEV_STREAM_CONFIG),
       map_str(DEV_RAW_STREAMS_PLAYBACK_CONTROL),
       map_str(DEV_READ_EEPROM),
       map_str(DEV_WRITE_EEPROM),
       map_str(DEV_SAMPLE),
       map_str(DEV_START),
       map_str(DEV_STOP),
       map_str(DEV_STATUS),
       map_str(DEV_GET_POSE),
       map_str(DEV_EXPOSURE_MODE_CONTROL),
       map_str(DEV_SET_EXPOSURE),
       map_str(DEV_GET_TEMPERATURE),
       map_str(DEV_SET_TEMPERATURE_THRESHOLD),
       map_str(DEV_SET_GEO_LOCATION),
       map_str(DEV_FLUSH),
       map_str(DEV_FIRMWARE_UPDATE),
       map_str(DEV_GPIO_CONTROL),
       map_str(DEV_TIMEOUT_CONFIGURATION),
       map_str(DEV_SNAPSHOT),
       map_str(DEV_READ_CONFIGURATION),
       map_str(DEV_WRITE_CONFIGURATION),
       map_str(DEV_RESET_CONFIGURATION),
       map_str(DEV_LOCK_CONFIGURATION),
       map_str(DEV_LOCK_EEPROM),
       map_str(DEV_SET_LOW_POWER_MODE),
       map_str(SLAM_STATUS),
       map_str(SLAM_GET_OCCUPANCY_MAP_TILES),
       map_str(SLAM_GET_LOCALIZATION_DATA),
       map_str(SLAM_SET_LOCALIZATION_DATA_STREAM),
       map_str(SLAM_SET_6DOF_INTERRUPT_RATE),
       map_str(SLAM_6DOF_CONTROL),
       map_str(SLAM_OCCUPANCY_MAP_CONTROL),
       map_str(SLAM_GET_LOCALIZATION_DATA_STREAM),
       map_str(SLAM_SET_STATIC_NODE),
       map_str(SLAM_GET_STATIC_NODE),
       map_str(SLAM_APPEND_CALIBRATION),
       map_str(SLAM_CALIBRATION),
       map_str(SLAM_RELOCALIZATION_EVENT),
       map_str(CONTROLLER_POSE_CONTROL),
       map_str(CONTROLLER_STATUS_CHANGE_EVENT),
       map_str(CONTROLLER_DEVICE_CONNECT),
       map_str(CONTROLLER_DEVICE_DISCOVERY_EVENT),
       map_str(CONTROLLER_DEVICE_DISCONNECT),
       map_str(CONTROLLER_READ_ASSOCIATED_DEVICES),
       map_str(CONTROLLER_WRITE_ASSOCIATED_DEVICES),
       map_str(CONTROLLER_DEVICE_DISCONNECTED_EVENT),
       map_str(CONTROLLER_DEVICE_CONNECTED_EVENT),
       map_str(CONTROLLER_RSSI_TEST_CONTROL),
       map_str(CONTROLLER_SEND_DATA),
       map_str(CONTROLLER_START_CALIBRATION),
       map_str(CONTROLLER_CALIBRATION_STATUS_EVENT),
       map_str(CONTROLLER_DEVICE_LED_INTENSITY_EVENT),
       map_str(DEV_ERROR),
       map_str(SLAM_ERROR),
       map_str(CONTROLLER_ERROR),
       map_str(MAX_MESSAGE_ID),
};

std::map<CONTROL_MESSAGE_ID, std::string> control_message_names = {
        map_str(CONTROL_USB_RESET),
        map_str(CONTROL_GET_INTERFACE_VERSION),
        map_str(MAX_CONTROL_ID),
};


template <typename T>
static std::string message_name(const T & header) {
    auto id = BULK_MESSAGE_ID(header.wMessageID);
    if(bulk_message_names.count(id) != 0) {
        return bulk_message_names.at(id);
    }
    std::stringstream s;
    s << std::hex << "UNKNOWN ID 0x" << id;
    return s.str();
}
