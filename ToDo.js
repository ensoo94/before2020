import React, {Component} from "react";
import {View, Text, TouchableOpacity, StyleSheet, Dimensions} from "react-native";

const { width, height } = Dimensions.get("window");

class ToDo extends Component{
    state = {
        isEditing: false,
        isCompleted: false
    };
    render(){
        const {isCompleted} = this.state;
        return (
            <View style = {styles.container}>
             <TouchableOpacity onPress={this._toggleComplete}>
                 <View style={[
                     styles.circle, 
                     isCompleted ? styles.completedCircle : styles.uncompletedCircle]} />
             </TouchableOpacity>
                <Text style = {styles.text}>Hello this is ToDo</Text>
            </View>        
        );
    };
    _toggleComplete = () => {
        this.setState(prevState => {
            return {
                isCompleted: !prevState.isCompleted
            };
        });
    };
}

const styles = StyleSheet.create({
    container: {
        width: width - 50,
        borderBottomColor: "#bbb",
        borderBottomWidth: StyleSheet.hairlineWidth,
        flexDirection: "row",
        alignItems: "center"
    },
    circle: {
        width: 30,
        height : 30,
        borderRadius: 15,
        marginRight: 20,
        borderColor: "#578CA9",
        borderWidth: 3
    },
    text: {
        fontWeight: "600",
        fontSize: 20,
        marginVertical: 20,
        fontWeight: "400",
        color: "#555"
    },
    uncompletedCircle:{
        borderColor: "#bbb"
    },
    completedCircle: {
        borderColor: "#578CA9"
    }
})

export default ToDo;