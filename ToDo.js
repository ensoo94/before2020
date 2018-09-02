import React, {Component} from "react";
import {View, Text, TouchableOpacity, StyleSheet, Dimensions} from "react-native";

const { width, height } = Dimensions.get("window");

class ToDo extends Component{
    state = {
        isEditing: false,
        isCompleted: false
    };
    render(){
        const {isCompleted, isEditing} = this.state;
        return (
            <View style = {styles.container}>
             <View style = {styles.column}>
                 <TouchableOpacity onPress={this._toggleComplete}>
                    <View style={[
                     styles.circle, 
                     isCompleted ? styles.completedCircle : styles.uncompletedCircle]} />
                </TouchableOpacity>
                <Text style = {[styles.text, 
                    isCompleted ? 
                    styles.completedText : styles.uncompletedText]}>
                    Hello this is todo
                </Text>
             </View>            
                {isEditing ?
                    <View style = {styles.action}>
                        <TouchableOpacity onPressOut={this._finishEditing}>
                            <View style={styles.actionContainer}>
                                <Text style={styles.actionText}>✔️</Text>
                            </View>
                        </TouchableOpacity>
                    </View>
                 : <View style = {styles.action}>
                    <TouchableOpacity onPressOut={this._startEditing}>
                        <View style={styles.actionContainer}>
                            <Text style={styles.actionText}>✨</Text>
                        </View>
                    </TouchableOpacity>
                    <TouchableOpacity>
                        <View style={styles.actionContainer}>
                            <Text style={styles.actionText}>✖️</Text>
                        </View>
                    </TouchableOpacity>
                </View>}      
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

    _startEditing = () => {
        this.setState({
            isEditing: true
        });
    };
    _finishEditing = () => {
        this.setState({
            isEditing: false
        });
    };
}

const styles = StyleSheet.create({
    container: {
        width: width - 50,
        borderBottomColor: "#bbb",
        borderBottomWidth: StyleSheet.hairlineWidth,
        flexDirection: "row",
        alignItems: "center",
        justifyContent: "space-between"
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
        fontWeight: "400"
    },
    uncompletedCircle:{
        borderColor: "#578CA9"
    },
    completedCircle: {
        borderColor:"#bbb"
    },
    uncompletedText: {
        color:"#353839"
    },
    completedText: {
        color: "#bbb",
        textDecorationLine: "line-through"
    },
    column:{
        flexDirection: "row",
        alignItems: "center",
        justifyContent:"space-between",
        width: width / 2
    },
    action: {
        flexDirection: "row"
    },
    actionContainer: {
        marginVertical: 10,
        marginHorizontal: 6
    }
})

export default ToDo;