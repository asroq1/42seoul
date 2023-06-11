import React from "react";

const DemoOutput = (props) => {
    console.log("demo running");
    return <p>{props.show ? 'this is new' : ''} </p>;
};

export default DemoOutput;