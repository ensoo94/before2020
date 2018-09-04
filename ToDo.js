import React, {Component} from "react";
import {View, Text, TouchableOpacity, StyleSheet, Dimensions, TextInput} from "react-native";
import { PropTypes } from "prop-types";

const { width, height } = Dimensions.get("window");


class ToDo extends Component{
    constructor(props) {
        super(props);
        this.state={ isEditing:false, toDoValue:props.text};
    }

    static propTypes = {
        text: PropTypes.string.isRequired,
        isCompleted: PropTypes.bool.isRequired,
        deleteToDo: PropTypes.func.isRequired,
        id: PropTypes.string.isRequired,
        uncompleteToDo: PropTypes.func.isRequired,
        completeToDo: PropTypes.func.isRequired
    };

    render(){
        const {isEditing, toDoValue} = this.state;
        const {isCompleted, text, id, deleteToDo} = this.props;
        return (
            <View style = {styles.container}>
             <View style = {styles.column}>
                 <TouchableOpacity onPress={this._toggleComplete}>
                    <View style={[
                     styles.circle, 
                     isCompleted ? styles.completedCircle : styles.uncompletedCircle]} />
                </TouchableOpacity>
                {isEditing ? (<TextInput 
                style={[styles.text,styles.input, isCompleted ? 
                    styles.completedText : styles.uncompletedText]} 
                value={toDoValue} 
                multiline={true}
                onChangeText={this._controlInput}
                returnKeyType={"done"}
                onBlur={this._finishEditing} />) : (
                    <Text style = {[styles.text, 
                        isCompleted ? 
                        styles.completedText : styles.uncompletedText]}>
                        {text}
                    </Text>
                )}
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
                    <TouchableOpacity onPressOut={() => deleteToDo(id)}>
                        <View style={styles.actionContainer}>
                            <Text style={styles.actionText}>✖️</Text>
                        </View>
                    </TouchableOpacity>
                </View>}      
            </View>        
        );
    };
    _toggleComplete = () => {
        const {isCompleted, uncompleteToDo, completeToDo, id} = this.props;
        if(isCompleted) {
            uncompleteToDo(id)
        } else {
            completeToDo(id)
        }
    };

    _startEditing = () => {
        const {text} = this.props;
        this.setState({
            isEditing: true,
            toDoValue: text
        });
    };
    _finishEditing = () => {
        this.setState({
            isEditing: false
        });
    };
    _controlInput = text => {
        this.setState({todoValue: text})
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
        width: width / 2
    },
    action: {
        flexDirection: "row"
    },
    actionContainer: {
        marginVertical: 10,
        marginHorizontal: 6
    },
    input: {
        marginVertical: 15,
        width: width / 2,
        paddingBottom: 5
    }
})

export default ToDo;