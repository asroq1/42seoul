import Item from "./Item";

function Expenses(props)
{
    // console.log(props.Item);

    return(
        <div className="expenses">
           {props.item.map((expenses) => (
                <Item key={expenses.key} date={expenses.date} amount={expenses.amount} title={expenses.title} />     
            ))}
        </div>
    )
}

export default Expenses;