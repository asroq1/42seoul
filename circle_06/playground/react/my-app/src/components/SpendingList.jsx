import './spendingList.css'

function SpendingList(props){
    return(
        <div className='expenses'>
            <h2>Used Amount is ${props.amount}</h2>
        </div>
    )
}

export default SpendingList;