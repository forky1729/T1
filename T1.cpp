#include <iostream>

namespace cat
{
    template<typename T>
    struct Node
    {
        T value;
        Node *next;
    };

    template<typename Iter, typename NodeType>
    struct InsertReturnType
    {
        Iter     position;
        bool     inserted;
        NodeType node;
    };

    template <typename Key, typename T, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>>
    class unordered_map
    {
        Key K;
        T value;

    public:
        //объявление имён ====================================================================
        using value_type = std::pair<const Key, T>;
        using size_type = std::size_t;
        using hasher = Hash;
        using key_equal = KeyEqual;
        using iterator = &value_type;
        using const_iterator = &const value_type;
        using local_iterator = iterator;
        using const_local_iterator = const_iterator;
        using node_type = Node;
        using insert_return_type = InsertReturnType;
        //(не используются в коде, но заявлены)
        //using key_type = Key;
        //using mapped_type = T;
        //using difference_type = std::ptrdiff_t;
        //using reference = value_type&;
        //using const_reference = const value_type&;
        //using pointer = ???;
        //using const_pointer = ???;

        //конструкторы =======================================================================
        ~unordered_map();
        unordered_map();
        unordered_map( size_type bucket_count );
        unordered_map( size_type bucket_count,
                    const Hash& hash );
        template< typename InputIt >
        unordered_map( InputIt first, InputIt last,
                    size_type bucket_count,
                    const Hash& hash = Hash(),
                    const key_equal& equal = key_equal() );
        template< typename InputIt >
        unordered_map( InputIt first, InputIt last,
                    size_type bucket_count )
        template< typename InputIt >
        unordered_map( InputIt first, InputIt last,
                    size_type bucket_count,
                    const Hash& hash );
        unordered_map( const unordered_map& other );
        unordered_map( unordered_map&& other );

        //методы =============================================================================
        unordered_map& operator=( unordered_map&& other );                                  //1
        unordered_map& operator=( const unordered_map& other );

        //Iterators
        template <typename T>                                                               //2
        T *begin();
        template <typename T>
        const T *begin() const;

        template <typename T>                                                               //3
        T *end();
        template <typename T>
        const T *end() const;

        //Capacity
        bool empty() const;                                                                 //4

        std::size_type size() const;                                                        //5

        std::size_type max_size() const;                                                    //6

        //Modifiers
        void clear();                                                                       //7

        std::pair<iterator,bool> insert( const value_type& value );                         //8
        std::pair<iterator,bool> insert( value_type&& value );
        template< typename P >
        std::pair<iterator,bool> insert( P&& value );
        iterator insert( const_iterator hint, const value_type& value );
        iterator insert( const_iterator hint, value_type&& value );
        template< typename P >
        iterator insert( const_iterator hint, P&& value );
        template< typename InputIt >
        void insert( InputIt first, InputIt last );
        insert_return_type insert( node_type&& nh );
        iterator insert( const_iterator hint, node_type&& nh );

        template< typename M >                                                              //9
        std::pair<iterator, bool> insert_or_assign( const Key& k, M&& obj );
        template< typename M >
        std::pair<iterator, bool> insert_or_assign( Key&& k, M&& obj );
        template< typename M >
        iterator insert_or_assign( const_iterator hint, const Key& k, M&& obj );
        template< typename M >
        iterator insert_or_assign( const_iterator hint, Key&& k, M&& obj );

        template< typename... Args >                                                        //10
        std::pair<iterator,bool> emplace( Args&&... args );

        template <typename... Args>                                                         //11
        iterator emplace_hint( const_iterator hint, Args&&... args );

        template< typename... Args >                                                        //12
        std::pair<iterator, bool> try_emplace( const Key& k, Args&&... args );
        template< typename... Args >
        std::pair<iterator, bool> try_emplace( Key&& k, Args&&... args );
        template< typename... Args >
        iterator try_emplace( const_iterator hint, const Key& k, Args&&... args );
        template< typename... Args >
        iterator try_emplace( const_iterator hint, Key&& k, Args&&... args );
        
        iterator erase( iterator pos );                                                     //13
        iterator erase( const_iterator pos );
        iterator erase( const_iterator first, const_iterator last );
        size_type erase( const Key& key );
        template< typename K >
        size_type erase( K&& x );

        void swap( unordered_map& other );                                                  //14

        node_type extract( const_iterator position );                                       //15
        node_type extract( const Key& k );
        template< typename K >
        node_type extract( K&& x );

        template<typename H2, typename P2>                                                  //16
        void merge( unordered_map<Key, T, H2, P2>& source );

        //Lookup
        T& at( const Key& key );                                                            //17
        const T& at( const Key& key ) const;

        T& operator[]( const Key& key );                                                    //18
        T& operator[]( Key&& key );

        size_type count( const Key& key ) const;                                            //19
        template< typename K >
        size_type count( const K& x ) const;

        iterator find( const Key& key );                                                    //20
        const_iterator find( const Key& key ) const;
        template< typename K >
        iterator find( const K& x );
        template< typename K >
        const_iterator find( const K& x ) const;

        bool contains( const Key& key ) const;                                              //21
        template< typename K >
        bool contains( const K& x ) const;

        std::pair<iterator,iterator> equal_range( const Key& key );                         //22
        std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;
        template< typename K >
        std::pair<iterator,iterator> equal_range( const K& x );
        template< typename K >
        std::pair<const_iterator,const_iterator> equal_range( const K& x ) const;

        //Bucket interface
        local_iterator begin( size_type n );                                                //23
        const_local_iterator begin( size_type n ) const;

        local_iterator end( size_type n );                                                  //24
        const_local_iterator end( size_type n ) const;

        size_type bucket_count() const;                                                     //25

        size_type max_bucket_count() const;                                                 //26

        size_type bucket_size( size_type n ) const;                                         //27

        size_type bucket( const Key& key ) const;                                           //28

        //Hash policy
        float load_factor() const;                                                          //29

        float max_load_factor() const;                                                      //30
        void max_load_factor( float ml );

        void rehash( size_type count );                                                     //31

        void reserve( size_type count );                                                    //32

        //Observers
        hasher hash_function() const;                                                       //33

        key_equal key_eq() const;                                                           //34

        //Non-member functions
        template <typename Key, typename T, typename Hash, typename KeyEqual>               //35
        bool operator==( const unordered_map<Key, T, Hash, KeyEqual>& lhs,
                         const unordered_map<Key, T, Hash, KeyEqual>& rhs );

        template <typename Key, typename T, typename Hash, typename KeyEqual>               //36
        bool operator!=( const unordered_map<Key, T, Hash, KeyEqual>& lhs,
                         const unordered_map<Key, T, Hash, KeyEqual>& rhs );

        template <typename Key, typename T, typename Hash, typename KeyEqual>               //37
        void swap( unordered_map<Key, T, Hash, KeyEqual>& lhs,
                   unordered_map<Key, T, Hash, KeyEqual>& rhs );

        template <typename Key, typename T, typename Hash, typename KeyEqual, typename Pred>//38
        typename unordered_map<Key, T, Hash, KeyEqual>::size_type
            erase_if( unordered_map<Key, T, Hash, KeyEqual>& c, Pred pred );
    
    }; //class unordered_map
} //namespace cat

#include <unordered_map>

int main()
{
    std::cout << "function        " << "arguments        " << "std        " << "cat        " << std::endl;
    std::cout << "" << std:: << "" << cat:: << std::endl;
}
