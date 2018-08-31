import React, { Component } from 'react';
import { StyleSheet, Text, View} from 'react-native';
import { LinearGradient} from 'expo';
import { MaterialCommunityIcons } from "@expo/vector-icons";
import PropTypes from "prop-types";

const weatherCases={
    Rain: {
        colors: ["#00C6FB", "#005BEA"],
        title: "Raining!",
        subtitle: "Take your umbrella",
        icon: "weather-rainy"
    },
    Clear: {
        colors: ["#FEF253", "#FF7300"],
        title: "Sunny!",
        subtitle: "The bright days are here",
        icon: "weather-sunny"
    },
    Thunderstorm:{
        colors: ["#00ECBC", "#007ADF"],
        title: "Thunder?",
        subtitle: "Thun-thun-thunder, thunder, thunder",
        icon: "weather-lightning"
    },
    Clouds: {
        colors: ["#D7D2CC", "#304352"],
        title: "Clouds,",
        subtitle: "These clouds stick to the sky",
        icon: "weather-cloudy"
    },
    Snowy: {
        colors: ["#7DE2FC", "#B9B6E5"],
        title: "White day!",
        subtitle: "Cold.. You are feeling oh so cold",
        icon: "weather-snowy"
    },
    Drizzle: {
        colors: ["#89F7FE", "#66A6FF"],
        title: "Drizzle!",
        subtitle: "Twinkle, twinkle, little waterdrop☔️",
        icon: "weather-hail"
    },
    Haze: {
        colors: ["#bac8e0", "#6a85b6"],
        title: "Haze!",
        subtitle: "I'm in a blue haze",
        icon: "weather-partlycloudy"
    },
    Mist: {
        colors: ["#fbc2eb", "#a18cd1"],
        title: "Mist!",
        subtitle: "Just stay quiet",
        icon: "weather-fog"
    }

}

function Weather({weatherName, temp}){
    return(
        <LinearGradient 
            colors={weatherCases[weatherName].colors} 
            style = {styles.container}
        >
            <View style = {styles.upper}>
                <MaterialCommunityIcons color="white" size={120} name={weatherCases[weatherName].icon} />
                <Text style ={styles.temp} >{temp}º</Text>
            </View>
            <View style={styles.lower}>
                <Text style={styles.title}>{weatherCases[weatherName].title}</Text>
                <Text style={styles.subtitle} >{weatherCases[weatherName].subtitle}</Text>
            </View>
        </LinearGradient>
    );
}

Weather.propTypes = {
    temp: PropTypes.number.isRequired
}

export default Weather;

const styles = StyleSheet.create({
    container: {
        flex: 1
    },
    upper: {
        flex: 1,
        alignItems:"center",
        justifyContent:"center",
        backgroundColor: "transparent"
    },
    temp: {
        fontSize: 48,
        color: "white",
        marginBottom: 24,
        backgroundColor: "transparent",
        fontWeight: "300",
        marginTop: 10
    },
    lower: {
        flex: 1,
        alignItems: "flex-start",
        justifyContent: "flex-end",
        paddingLeft: 25
    },
    title: {
        fontSize: 38,
        color: "white",
        marginBottom: 10,
        backgroundColor: "transparent",
        fontWeight: "300"
    },
    subtitle: {
        fontSize: 24,
        color: "white",
        marginBottom: 30,
        backgroundColor: "transparent",
        fontWeight: "300"
    }
})